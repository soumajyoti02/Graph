Question : Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.;

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
  
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.;

========================================================================================================================

Approach:
Initial configuration:
Queue: Define a queue and insert the source node along with parent data (<source node, parent>). For example, (2, 1) means 2 is the source node and 1 is its parent node.
Visited array: an array initialized to 0 indicating unvisited nodes. 
  
  --------------------------------------
  
The algorithm steps are as follows:

For BFS traversal, we need a queue data structure and a visited array. 
  
--> Push the pair of the source node and its parent data (<source, parent>) in the queue, and mark the node as visited. 
    The parent will be needed so that we don’t do a backward traversal in the graph, we just move frontwards. 
      
--> Start the BFS traversal, pop out an element from the queue every time and travel to all its unvisited neighbors using an adjacency list.
      
--> Repeat the steps either until the queue becomes empty, or a node appears to be already visited which is not the parent, 
    even though we traveled in different directions during the traversal, indicating there is a cycle.
      
--> If the queue becomes empty and no such node is found then there is no cycle in the graph;



Code Below :::  (BFS =>)


class Solution {
    
  private: 
  bool detectCycle(int src, int *vis, vector<int> adj[])
  {
      queue<pair<int, int> > q;
      q.push({src, -1});
      vis[src] = 1;
      while(!q.empty())
      {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto it : adj[node])
          {
              if(!vis[it])
              {
                  q.push({it, node});
                  vis[it] = 1;
              }
              else if(parent != it) return true;
          }
      }
      return false;
  }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                bool dct = detectCycle(i, vis, adj);
                if(dct) return true;
            }
        }
        return false;
    }
};



===================================================================================
  
DFS APPROACH :

Algorithm: 

--> Create the graph using the given number of edges and vertices.
  
--> Create a recursive function that have current index or vertex, visited array and parent node.
  
--> Mark the current node as visited .
  
--> Find all the vertices which are not visited and are adjacent to the current node. 
  Recursively call the function for those vertices, If the recursive function returns true return true.
    
--> If the adjacent node is not parent and already visited then return true.
--> Create a wrapper function, that calls the recursive function for all the vertices and if any function returns true, 
    return true. (Because all the nodes in the graph might not be connected or reachable from a starting vertex. 
    To make sure every vertex of graph is connected we are calling the recursive function for all unvisited nodes.)
  
  
--> Else if for all vertices the function returns false return false.

------------------------------------------------------------------------

Code Below :::  (DFS =>)

class Solution {
    
  private:
  bool detect(int start, int parent, vector<int> adj[], int *vis)
  {
      vis[start] = 1;
      for(auto it : adj[start])
      {
          if(!vis[it])
          {
              if(detect(it, start, adj, vis) == true)
                return true;
          }
          else if(it != parent)
            return true;
      }
      return false;
  }
  
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 1; i < V; i++)
        {
            if(!vis[i])
            {
                if(detect(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};


  
  
  
  
  
