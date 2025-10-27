// Min Path Sum 
#include <iostream>
using namespace std;
// using recurssion ( giving tle )
class Solution {
public:
    int f(int i,int j, vector<vector<int>>&grid){
        if (i == 0 && j == 0) 
            return grid[0][0];
        
        if (i < 0 || j < 0) 
            return INT_MAX;

        int up = grid[i][j]+f(i-1,j,grid);
        int left = grid[i][j]+f(i,j-1,grid);
        return min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return f(m - 1, n - 1, grid);
    }
};

// using memoisation (works)
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp) {
        if (i == 0 && j == 0) 
            return grid[0][0];
        
        if (i < 0 || j < 0) 
            return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = f(i - 1, j, grid,dp);
        int left = f(i, j - 1, grid,dp);

        int upCost = (up == INT_MAX) ? INT_MAX : grid[i][j] + up;
        int leftCost = (left == INT_MAX) ? INT_MAX : grid[i][j] + left;

        return dp[i][j]=min(upCost, leftCost);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid,dp);
    }
};


// tabulation 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) dp[i][j]=grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j]+dp[i-1][j];
                    if(j>0) left = grid[i][j]+dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};