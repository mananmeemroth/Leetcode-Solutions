#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsofGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;
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
    vector<int> bfsTraversal = sol.bfsofGraph(V, adj);

    cout << "BFS Traversal starting from node 0: ";
    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
