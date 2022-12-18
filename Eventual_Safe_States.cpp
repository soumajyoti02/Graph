Question : A directed graph of V vertices and E edges is given in the form of an adjacency list adj;
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order;

=============================================================================================================================================================

Approach: 
---> We will be solving it using DFS traversal. DFS goes in-depth, i.e., 
traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path,
then it backtracks on the same path and traverses other unvisited nodes.
  
================>>>>>>> The algorithm steps are as follows:

---> We must traverse all components of the graph.
  
---> Make sure to carry two visited arrays in the DFS call. One is a visited array(vis) and the other is a path-visited(pathVis) array;

---> The visited array keeps a track of visited nodes, and the path-visited keeps a track of visited nodes in the current traversal only.
  
---> Along with that, we will be carrying an extra array(check) to mark the safe nodes.
  
---> While making a DFS call, at first we will mark the node as visited in both the arrays and then will traverse through its adjacent nodes;
Now, there may be either of the three cases:

---> Case 1: If the adjacent node is not visited, we will make a new DFS call recursively with that particular node.
  
---> Case 2: If the adjacent node is visited and also on the same path(i.e marked visited in the pathVis array), we will return true,
because it means it has a cycle, thereby the pathVis was true. Returning true will mean the end of the function call, as once we have got a cycle, 
there is no need to check for further adjacent nodes.
  
---> Case 3: If the adjacent node is visited but not on the same path(i.e not marked in the pathVis array),
we will continue to the next adjacent node, as it would have been marked as visited in some other path, and not on the current one.
  
---> Finally, if there are no further nodes to visit, we will mark the node as safe in the check array and 
unmark the current node in the pathVis array and just return false. Then we will backtrack to the previous node with the returned value.
  
---> The Point to remember is, while we enter we mark both the pathVis and vis as true, but at the end of traversal to all adjacent nodes, 
we just make sure to mark the current node safe and unmark the pathVis and still keep the vis marked as true, as it will avoid future extra traversal calls.
  
  
  
CODE BELOW ::::::


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[],
 int pathVis[], 
        int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}
};


int main() {

	//V = 12;
	vector<int> adj[12] = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, 
        {8},{9}};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}
Output: 0 1 2 3 4 5 6 7

Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity
  
  
  
  
  
  
  
  
  
