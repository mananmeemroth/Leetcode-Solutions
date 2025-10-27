#include <iostream>
using namespace std;
// recurssion 

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;  // invalid column
        if (i == 0) return matrix[0][j];  // base case: top row
        
        int st = matrix[i][j] + f(i - 1, j, matrix);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix);
        
        return min(st, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;

        // Try all possible ending positions in the last row
        for (int j = 0; j < n; j++) {
            mini = min(mini, f(n - 1, j, matrix));
        }
        return mini;
    }
};

// memoisation

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;  // invalid column
        if (i == 0) return matrix[0][j];  // base case: top row
        if(dp[i][j]!=-1) return dp[i][j];
        
        int st = matrix[i][j] + f(i - 1, j, matrix,dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix,dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix,dp);
        
        return dp[i][j]=min(st, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for (int j = 0; j < n; j++) {
            mini = min(mini, f(n - 1, j, matrix,dp));
        }
        return mini;
    }
};


// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int st = dp[i-1][j];
                int ld = 1e9;
                int rd = 1e9;
                if(j-1>=0){
                     ld = dp[i-1][j-1];
                }
                if(j<n-1) rd = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(st, min(ld, rd));
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

        
//         // The result is the minimum value in the last row of dp
//         int mini = 1e9;
//         for (int j = 0; j < n; j++) {
//             mini = min(mini, dp[n - 1][j]);
//         }
        
//         return mini;
//     }
// };