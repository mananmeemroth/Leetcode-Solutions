#include <iostream>
using namespace std;
// dfs
class Solution {
public:
    // vis: -1 = unvisited, 0 = visiting, 1 = safe
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node] != -1)        // already processed
            return vis[node] == 1;  // true if safe, false if unsafe

        vis[node] = 0; // mark as visiting (part of current recursion stack)

        for (int nei : adj[node]) {
            if (!dfs(nei, adj, vis))   // if a neighbor is unsafe
                return false;          // this node is unsafe too
        }

        vis[node] = 1; // all neighbors safe → this node is safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, vis))
                res.push_back(i);
        }

        return res;
    }
};

// BFS
