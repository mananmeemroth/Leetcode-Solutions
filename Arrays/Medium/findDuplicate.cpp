#include <iostream>
using namespace std;
// but it is not efficient(giving runtime error)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                index =i;
            }
        }
        return nums[index];
    }
};

// efficient one 
// #hint use : binary search 

// Complexity

// Time complexity: O(NlogN)
// Space complexity: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            int count=0;
            for(int num: nums){
                if(num<=mid) count++;      // Count the numbers less than or equal to mid
            }
            if(count>mid) right = mid;     // If count is greater than mid, the duplicate lies in the left half
            else left = mid+1;             // Otherwise, it lies in the right half
        }
        return left;
    }
};


// 2 pointer approach 
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};