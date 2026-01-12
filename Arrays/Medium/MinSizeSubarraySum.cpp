#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = n - 2;   // second last
        int j = n - 1;   // last

        while (i >= 0) {
            int sum = nums[i] + nums[j];

            if (sum == target) {
                return (j - i + 1);
            }
            else if (sum > target) {
                i--;   // decrease sum
            }
            else {
                j--;   // move both left if needed
                i--;
            }
        }

        return 0; // if no such pair found
    }
};



