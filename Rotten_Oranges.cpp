Question : Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time;

================================================================================================================

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.;


Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).;


Approach : Make a 2D visited array and store the already rotten oranges. I mean at that index, make vis[i][j] = 2; Store the i and j in a queue also;
Maintain a part in queue which will take care of times;
Also Count the total Non- rotten oranges in that loop.

Then simply start the BFS while(!queue.empty())
  Extract the q.front();
  Check the Neighbours of them, Which neighbour has non-rotten orange, enter thats index i.e. i and j into the queue;
  Record the maximum time in a seperate variable using max(tm,t);

Return max time variable;



Code Below:::::



class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int, int>, int> > q;
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        int totalCount = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2) 
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) totalCount++;
            }
        }
        
        int tm = 0;
        int cnt = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            tm = max(tm,t);
            q.pop();
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1 and vis[nr][nc] == 0)
                {
                    cnt++;
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }
        
        if(totalCount != cnt) return -1;
        return tm;
    }
};













