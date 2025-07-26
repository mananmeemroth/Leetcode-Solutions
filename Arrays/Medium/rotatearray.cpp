#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> arr1;
        for (int i = n - k; i < n; i++) {
            arr1.push_back(nums[i]);
        }
        
        for (int i = 0; i < n - k; i++) {
            arr1.push_back(nums[i]);
        }
        
        nums = arr1;
    }
};
