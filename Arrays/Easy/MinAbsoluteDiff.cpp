#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mindiff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            if(diff<mindiff){
                mindiff=diff;
            }
        }
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            if(diff==mindiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};