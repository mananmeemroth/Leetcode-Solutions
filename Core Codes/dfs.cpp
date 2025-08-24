#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
public:
    vector<int> dfsofGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> ls;
        dfs(0, adj, vis, ls);
        return ls;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    Solution sol;
    vector<int> dfsTraversal = sol.dfsofGraph(V, adj);

    cout << "DFS Traversal starting from node 0: ";
    for (int node : dfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
