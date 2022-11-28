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

========================================================================================

Approach : Make a 2D visited array and store the already rotten oranges. I mean at that index, make vis[i][j] = 2; Store the i and j in a queue also;
Maintain a part in queue which will take care of times;
Also Count the total Non- rotten oranges in that loop.

Then simply start the BFS while(!queue.empty())
  Extract the q.front();
  Check the Neighbours of them, Which neighbour has non-rotten orange, enter thats index i.e. i and j into the queue;
  Record the maximum time in a seperate variable using max(tm,t);

Return max time variable;

-----------------------------------------------

The algorithm steps are as follows:

---> For BFS traversal, we need a queue data structure and a visited array. Create a replica of the given array, i.e., 
     create another array of the same size and call it a visited array. We can use the same matrix, but we will avoid alteration of the original data. 
       
---> The pairs of cell number and initial time, i.e., <<row, column>, time> will be pushed in the queue and marked as visited 
     (represents rotten) in the visited array. For example, ((2,0), 0) represents cell (2, 0) and initial time 0.  
       
---> While BFS traversal, pop out an element from the queue and travel to all its neighbours. In a graph, we store the 
      list of neighbours in an adjacency list but here we know the neighbours are in 4 directions. 
       
---> We go in all 4 directions and check for valid unvisited fresh orange neighbours. To travel 4 directions we will use nested loops,
     you can find the implementation details in the code. 
---> BFS function call will make sure that it starts the BFS call from each rotten orange cell, and rotten all the 
     valid fresh orange neighbours and puts them in the queue with an increase in time by 1 unit. Make sure to mark it as rotten in the visited array. 
       
---> Pop-out another rotten orange from the queue and repeat the same steps until the queue becomes empty.
       
---> Add a counter variable to store the maximum time and return it. If any of the fresh was not rotten in the visited array then return -1.

 =====================================================================================================
       
Code Below:::::



#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector < vector < int >> & grid) {
      // figure out the grid size
      int n = grid.size();
      int m = grid[0].size();

      // store {{row, column}, time}
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      // delta row and delta column
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      // bfs traversal (until the queue becomes empty)
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          // check for valid cell and 
          // then for unvisited fresh orange
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
            // push in queue with timer increased
             q.push({{nrow, ncol}, t + 1}); 
            // mark as rotten
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      // if all oranges are not rotten
      if (cnt != cntFresh) return -1;

      return tm;

    }
};

int main() {

  vector<vector<int>>grid{{0,1,2},{0,1,2},{2,1,1}};
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";

  return 0;
}






