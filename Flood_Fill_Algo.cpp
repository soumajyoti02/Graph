Question : Here a 2D matrix and a point is given (image[sr][sc]); Also A new colour code is given. We have to change the adjecent numbers of image[sr][sc] into the
new number. Only those neighbour''s value will be changed who has the same Previous valu as the image[sr][sc];

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.;

=============================================================
  
Approach :
i) Store the Colour of image [sr][sc] in a variable colour;
ii) Call the DFS function;
iii) return Image;

In DFS ::
1. Change the colour of image[sr][sc] = newColour;
2. Check the 4 directions who has same value as previous image[sr][sc]; -->
      int delrow[] = {-1, 0, 1, 0};
      int delcol[] = {0, 1, 0, -1};
      for(int i = 0; i < 4; i++)
      {
        int nr = sr + delrow[i];
        int nc = sc + delcol[i];
      }
3. Call DFS recursively;




Code Below :::::



class Solution {
    
private:
void helper(vector<vector<int> >& ans, vector<vector<int>> image, int color, 
            int row, int col, int delrow[], int delcol[],int newColor)
{
    ans[row][col] = newColor;
    for(int i = 0; i < 4; i++)
    {
        int nr = row + delrow[i];
        int nc = col + delcol[i];
        
        if(nr >= 0 and nr < ans.size() and nc >= 0 and nc < ans[0].size() and 
           ans[nr][nc] != newColor and image[nr][nc] == color)
           {
               helper(ans,image,color,nr,nc,delrow,delcol,newColor);
           }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, 
    int newColor) {
        // Code here 
        vector<vector<int> > ans = image;
        int color = image[sr][sc];
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        helper(ans,image,color,sr,sc, delrow, delcol,newColor);
        return ans;
    }
};
  
  
  
