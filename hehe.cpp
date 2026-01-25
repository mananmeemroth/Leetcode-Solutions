#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // Use three pointers: low, mid, and high
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[low] and nums[mid] and move both pointers
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // No swap needed, just move mid pointer
                mid++;
            }
            else {
                // Swap nums[mid] and nums[high] and move high pointer
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
