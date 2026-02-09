#include <iostream>
using namespace std;
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {find(nums, target, true), find(nums, target, false)};
//     }

//     int find(vector<int>& nums, int target, bool findFirst) {
//         int low = 0, high = nums.size() - 1, ans = -1;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (nums[mid] == target) {
//                 ans = mid;
//                 if (findFirst) high = mid - 1;
//                 else low = mid + 1;
//             } else if (nums[mid] < target) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int firstocurrence(vector<int>& nums,int target){
        int n=nums.size();
        int low =0,high = n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    int lastocurrence(vector<int>& nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first= firstocurrence(nums,target);
        int last = lastocurrence(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};

