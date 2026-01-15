// 2943. Maximize Area of Square Hole in Grid
// Day: 15 Jan 2026

// in this we are given a grid an
#include <iostream>
using namespace std;

class Solution {
private:
    int maxLen(vector<int>& Bars){
        int streak=2,length=2;
        for(int i=1;i<Bars.size();i++){
            if(Bars[i]-Bars[i-1]==1) streak++;
            else streak=2;
            length = max(streak,length);
        }
        return length;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int side= min(maxLen(hBars),maxLen(vBars));
        return (side-1)*(side-1);
    }
};