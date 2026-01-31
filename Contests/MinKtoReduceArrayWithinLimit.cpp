#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int nonPositive(const vector<int>& nums,int k){
        int ops = 0;
        for(int num:nums){
            ops+=(num+k-1)/k;
        }
        return ops;
    }
    int minimumK(vector<int>& nums) {
        int left =1,right =100000;
        int ans =right;
        while(left<=right){
            int mid = left+(right-left)/2;
            long long ops=nonPositive(nums,mid);
            long long kSquared = (long long)mid * mid;
            if(ops<=kSquared){
                ans=mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};