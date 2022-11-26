Question : Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land);
Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions;

-------------------------------=============================================--------------------------------

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.;


Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.;

------------------------------------------------------------------------------------

APPROACH :::::


Follow the steps below to solve the problem:

--> Initialize a boolean matrix visited of the size of the given matrix to false.
--> Initialize count = 0, to store the answer.
--> Traverse a loop from 0 till ROW
--> Traverse a nested loop from 0 to COL
--> If the value of the current cell in the given matrix is 1 and is not visited
--> Call BFS function
    i) Declare a queue<int> to store the i and j value of the Matrix.
    ii) Start the BFS while loop (!queue.empty())
    iii) Extract and store the queue.front().first and queue.front().second; then pop the queue;
     iv) Check the 8 dirction of that point in grid matrix, Where 1 is found, Store that i and j also;
--> Increment count by 1
--> Return count as the final answer;

==============================================================

Code Below ::::::::::::


class Solution {
  public:
  
    
    void bfs(int r, int c, vector<vector<char>> grid, vector<vector<int >>& vis)
    {
        queue<pair<int, int> > q;
        q.push({r, c});
        vis[r][c] = 1;
        int row = grid.size();
        int col = grid[0].size();
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // Short Way to Check all 8 dirctions: [-1][0], [+1][0] ,[0][-1] ,[0][+1] ,[+1][+1] ,[+1][-1] ,[-1][+1] ,[-1][-1] ;
            for(int delr = -1; delr <= 1; delr++)
            {
                for(int delc = -1; delc <= 1; delc++)
                {
                    int nr = r + delr;
                    int nc = c + delc;
                    if(nr >= 0 and nr < row and nc >= 0 and nc < col and 
                    grid[nr][nc] == '1' and vis[nr][nc] == 0)
                    {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(row, vector<int>(col,0));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
