#include <iostream>
using namespace std;


class Solution{
public:
    bool isTrionic(vector<int>& nums){
        int i=0;
        int n=nums.size();
        while(i<n&&nums[i]>nums[i-1]) i++;
        if(i<2||i==n) return false;
        while(i<n&&nums[i]<nums[i-1]) i++;
        if(i<3||i==n) return false;
        while(i<n&&nums[i]>nums[i-1]) i++;
        return i==n;
    }
};