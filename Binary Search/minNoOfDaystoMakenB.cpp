#include <iostream>
using namespace std;

class Solution {
public:
    bool canmakebq(vector<int>& bloomDay,int m,int k,int day){
        int total=0;
        for(int i=0;i<bloomDay.size();i++){
            int cnt=0;
            while(i<bloomDay.size()&& cnt<k&& bloomDay[i]<=day){
                cnt++;
                i++;
            }
            if(cnt==k){
                total++;
                i--;
            }
            if(total>=m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=1,high=1e9;
        while(low<high){
            int mid=low+(high-low)/2;
            if(canmakebq(bloomDay,m,k,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
