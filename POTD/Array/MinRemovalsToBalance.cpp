#include <iostream>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,maxlen=0;
        for(int j=0;j<n;j++){
            while(nums[j]>k*nums[i]){
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return n-maxlen;
    }
};