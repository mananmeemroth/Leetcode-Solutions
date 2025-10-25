#include <iostream>
#include <vector>
using namespace std;

// recurssion
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        int up = f(i-1,j,obstacleGrid);
        int left = f(i,j-1,obstacleGrid);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==0 || n==0) return 0;
        return f(m-1,n-1,obstacleGrid);
    }
}; 

// memoisation
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;  // Outside grid bounds
        if (obstacleGrid[i][j] == 1) return 0;  // Obstacle
        if (i == 0 && j == 0) return 1;  // Reached start
        if (dp[i][j] != -1) return dp[i][j];  // Already computed
        // Move up and left
        int up = f(i - 1, j, obstacleGrid, dp);
        int left = f(i, j - 1, obstacleGrid, dp);
        return dp[i][j] = up + left;  // Store result in dp
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 0 || n == 0) return 0;
        // If the start or end position has an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        // Create the dp table with the correct dimensions
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};
// tabuation
// tabulation
class Solution {
public:
    int f(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // if there's an obstacle, no path
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1; // starting point
                }
                else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i - 1][j];
                    if (j > 0) left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // edge case: if start or end is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        return f(m, n, obstacleGrid, dp);
    }
};
