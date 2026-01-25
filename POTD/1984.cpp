#include <iostream>
using namespace std;
// using sliding window;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k) return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=i+k-1;
        int maxi=INT_MAX;
        while(j<n){
            maxi=min(maxi,nums[j]-nums[i]);
            j++;
            i++;
        }
        return maxi;
    }
};
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[k - 1] - nums[0];
        for(int i = 0; i + k <= n; i ++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};