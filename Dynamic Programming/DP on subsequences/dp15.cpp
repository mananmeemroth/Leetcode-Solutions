// partition equal subset sum 
#include <iostream>
using namespace std;
class Solution {
public:
    bool subsetsumtoK(int n,int k, vector<int>& arr){
        vector<bool> prev(k+1,0),cur(k+1,0);
        prev[0] = cur[0] = true;
        prev[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;

        for(int ind = 1;ind<n;ind++){
            for(int target =1;target<=k;target++){
                bool nottake = prev[target];
                bool take = false;
                if(arr[ind]<=target) take = prev[target-arr[ind]];
                cur[target] = take|nottake;
            }
            prev = cur;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum =0;
        for(int i=0;i<n;i++) totsum+=nums[i];
        if(totsum%2) return false;
        int target = totsum/2;
        return subsetsumtoK(n,target,nums);
    }
};


