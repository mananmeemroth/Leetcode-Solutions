#include <iostream>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == 0) return;

        grid[i][j] = 0;
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n - 1) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1) dfs(i, j, grid);
                }
            } else {
                if(grid[i][0] == 1) dfs(i, 0, grid);
                if(grid[i][m - 1] == 1) dfs(i, m - 1, grid);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};