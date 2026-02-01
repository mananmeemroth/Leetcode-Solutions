#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negno;
        vector<int> posno;
        for(int n:nums){
            if(n<0){
                negno.push_back(n);
            }else{
                posno.push_back(n);
            }
        }
        int n=nums.size();
        vector<int> ans;
        int i=0;
        while(i<n/2){
            ans.push_back(posno[i]);
            ans.push_back(negno[i]);
            i++;
        }
        return ans;
    }
};