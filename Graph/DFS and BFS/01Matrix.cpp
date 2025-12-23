#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();          // Rows
        int m = mat[0].size();       // Columns
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited matrix
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX)); // Distance matrix
        queue<pair<int, int>> q;  // Queue to hold coordinates
        
        // Initialize the queue with all 0s in the matrix and set their distance to 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;  // Distance of 0s is always 0
                    vis[i][j] = 1;  // Mark as visited
                }
            }
        }

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};
        
        // Perform BFS
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Check 4 directions (up, down, left, right)
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // Check if the new position is within bounds and not yet visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    // Update the distance to the minimum distance found
                    dis[nrow][ncol] = dis[row][col] + 1;
                    vis[nrow][ncol] = 1;  // Mark as visited
                    q.push({nrow, ncol});  // Push to the queue for further exploration
                }
            }
        }
        
        return dis;
    }
};
