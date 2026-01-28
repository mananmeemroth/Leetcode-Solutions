#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        vector<int> ans;
        int n=nums.size()/3;
        for(int num:nums) freqMap[num]++;
        for(auto &it:freqMap){
            if(it.second>n) ans.push_back(it.first);
        }
        return ans;
    }
};