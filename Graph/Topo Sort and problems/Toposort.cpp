#include <iostream>
using namespace std;
class Solution{
public:
    void dfs(int node,vector<int> adj[], vector<int>& vis, stack<int>& st){
        return;
    }
    vector<int> topoSort(int V,vector<int> adj[]){
        
    }
};




class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    // Function to perform Topological Sort
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Create a visited array to mark visited vertices
        vector<int> vis(V, 0);

        // Stack to store vertices in finishing order
        stack<int> st;

        // Perform DFS from each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Prepare the result array
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Return the topological ordering
        return ans;
    }
};

// Driver code
int main() {
    // Number of vertices and edges
    int V = 6, E = 6;

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Create an object of Solution
    Solution obj;

    // Get the topological order
    vector<int> res = obj.topoSort(V, adj);

    // Print the result
    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
