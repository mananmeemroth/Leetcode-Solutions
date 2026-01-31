#include <iostream>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<int> ways(n,0);
        ways[0]=1;

        vector<long long> distance(n,LLONG_MAX);
        distance[0]=0;

        vector<vector<pair<int,int>>> adj(n);
        for(auto& it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        // Modulo value to avoid overflow for large path counts
        const int MOD = 1e9 + 7;

        // ways[i] = number of shortest paths to reach node i
        vector<int> ways(n, 0);
        ways[0] = 1;   // There is exactly 1 way to stay at the starting node (node 0)

        // distance[i] = shortest distance from node 0 to node i
        vector<long long> distance(n, LLONG_MAX);
        distance[0] = 0;   // Distance to starting node is 0

        // Adjacency list: adj[u] contains {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : roads) {
            // Since the graph is undirected, add both directions
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Min-heap priority queue
        // Stores {current distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Start Dijkstra from node 0
        pq.push({0, 0});

        // Dijkstra's algorithm
        while (!pq.empty()) {

            // Get node with smallest distance
            auto [dist, node] = pq.top();
            pq.pop();

            // If this distance is outdated, skip
            if (dist > distance[node]) continue;

            // Explore all neighbors of current node
            for (auto &it : adj[node]) {
                int adjNode = it.first;   // Neighbor node
                int edW = it.second;     // Edge weight

                // New possible distance to neighbor
                long long newDist = dist + edW;

                // Case 1: Found a shorter path
                if (newDist < distance[adjNode]) {
                    distance[adjNode] = newDist;      // Update shortest distance
                    ways[adjNode] = ways[node];       // Inherit number of ways
                    pq.push({newDist, adjNode});       // Push to heap
                }

                // Case 2: Found another shortest path
                else if (newDist == distance[adjNode]) {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        // Return number of shortest paths to node n-1
        return ways[n - 1] % MOD;
    }
};
