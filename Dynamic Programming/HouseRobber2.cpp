#include <iostream>
using namespace std;
class Solution {
private:
    int solve(vector<int>& nums, int start, int end)
    {
        if(end-start == 1)
            return nums[start];
        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start+1]);

        for(int i = start+2; i < end; i++)
        {
            // curr = max{include, exclude}
            int curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        
        return max(solve(nums, 0, nums.size()-1), solve(nums, 1, nums.size()));
    }
};