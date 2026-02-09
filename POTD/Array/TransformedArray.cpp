#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int move = nums[i] % n;
            int newIdx = (i+move)%n;
            if(newIdx<0){
                newIdx+=n;
            }
            result.push_back(nums[newIdx]);
        }
        return result;
    }
};