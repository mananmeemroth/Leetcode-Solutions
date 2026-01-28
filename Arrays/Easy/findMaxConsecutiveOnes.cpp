#include <iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int cnt=0;
        for(int i:nums){
            if(i==1){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;

            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};