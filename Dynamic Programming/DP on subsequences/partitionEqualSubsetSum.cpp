// partition equal subset sum 
#include <iostream>
using namespace std;
class Solution {
public:
    bool subsetSumUtil(int ind, int target,vector<int>&arr, vector<vector<int>>& dp){
        if(target==0) return true;
        if(ind==0) return arr[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottaken=subsetSumUtil(ind-1,target,arr,dp);
        bool taken = false;
        if(arr[ind]<=target){
            taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target]=nottaken||taken;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<nums.size();i++) totalsum+=nums[i];
        if(totalsum%2) return false;
        int target = totalsum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return subsetSumUtil(n-1,target,nums,dp);
    }
};