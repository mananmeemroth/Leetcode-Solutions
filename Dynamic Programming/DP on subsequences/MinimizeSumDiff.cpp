#include <iostream>
using namespace std;
// this is not going to work for this, but will work in gfg

class Solution{
public:
    int minimumDifference(vector<int>& nums){
        int n=nums.size(),totSum=0;
        for(int i=0;i<n;i++)totSum+=nums[i];
        vector<vector<bool>> dp(n,vector<bool>(totSum+1,0));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=totSum)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=totSum;t++){
                bool notTake=dp[i-1][t];
                bool take=false;
                if(nums[i]<=t)take=dp[i-1][t-nums[i]];
                dp[i][t]=take|notTake;
            }
        }
        int ans=1e9;
        for(int s1=0;s1<=totSum/2;s1++){
            if(dp[n-1][s1])ans=min(ans,abs(totSum-2*s1));
        }
        return ans;
    }
};

// Meet in the middle approach is going to work in this case

