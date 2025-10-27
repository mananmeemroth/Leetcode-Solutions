// Triangle
#include <iostream>
using namespace std;
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         for (int i = triangle.size() - 2; i >= 0; i--)
//             for (int j = 0; j < triangle[i].size(); j++)
//                 triangle[i][j] +=
//                     min(triangle[i + 1][j], triangle[i + 1][j + 1]);

//         return triangle[0][0];
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j]+dp[i+1][j];
                int dg = triangle[i][j]+dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};