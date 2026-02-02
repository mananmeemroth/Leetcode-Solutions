// 2nd part of the divide array into subarray with min cost
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    multiset<int> low,high;
    long long sumL=0;
    int m;
    void add(int x){
        if(low.size()<m){
            sumL+=x;
            low.insert(x);
        }else{
            auto rmv=prev(low.end());
            if(*rmv>x){
                sumL-=(*rmv);
                high.insert(*rmv);
                low.erase(rmv);
                
                low.insert(x);
                sumL+=x;
            }else{
                high.insert(x);
            }
        }
    }
    void remove(int x){
        auto it1=low.find(x);
        auto it2=high.begin();
        if(it1!=low.end()){
            low.erase(it1);
            sumL-=x;
            
            low.insert(*it2);
            sumL+=*it2;

            high.erase(it2);
        }else{
            high.erase(high.find(x));
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        
        int n=nums.size();
        m=k-1;
        int l=1,r=dist+l;
        for(int i=l;i<=r;i++){
            add(nums[i]);
        }
        long long minm=sumL;
        r++;
        while(r<n){
            add(nums[r]);
            remove(nums[l]);
            l++;
            minm=min(minm,sumL);
            r++;
        }
        return minm+nums[0];
    }
};