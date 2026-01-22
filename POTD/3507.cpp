#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations=0;
        while(!is_sorted(nums.begin(), nums.end())){
            int minSum=INT_MAX;
            int idx=-1;
            
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<minSum){
                    minSum=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            nums[idx] = nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            operations++;
            
        }
        return operations;
    }
};
