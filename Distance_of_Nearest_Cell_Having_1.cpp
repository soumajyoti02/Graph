Question : Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 
are the row number and column number of the nearest cell having value 1;

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1''s at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
  

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1''s at (0,0),
(0,2), (2,0) and (1,1) respectively;

====================================================

APPROACH : 

Steps:

Traverse the matrix from start to end (using two nested loops) and store the 1s position in a queue<pair<pair<int, int>, int> > q with distance 0;
Start the BFS and store the q.front().second in ans[r][c] in every loop itertion;
Return the answer vector;

======================================================
  
Code Below :


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size();
	    int col = grid[0].size();
	    vector<vector<int> > vis(row, vector<int>(col, 0));
	    vector<vector<int> > dist(row, vector<int>(col, 0));
	    queue<pair<pair<int, int>, int> > q;
	    
	    for(int i = 0; i < row; i++)
	    {
	        for(int j = 0; j < col; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    
	    int dr[] = {-1, 0, 1, 0};
	    int dc[] = {0, 1, 0, -1};
	    
	    while(!q.empty())
	    {
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        dist[r][c] = steps;
	        
	        
	        for(int i = 0; i < 4; i++)
	        {
	            for(int j = 0; j < 4; j++)
	            {
	                int nr = r + dr[i];
	                int nc = c + dc[i];
	                
	                if(nr >= 0 and nr < row and nc >= 0 and nc < col and vis[nr][nc] == 0)
	                {
	                    vis[nr][nc] = 1;
	                    q.push({{nr, nc}, steps + 1});
	                }
	            }
	        }
	    }
	   return dist;
	}
};

  
  
  
  
  
  
  
  
  
  
  
