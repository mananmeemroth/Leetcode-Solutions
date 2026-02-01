#include <iostream>
using namespace std;
class Solution {
public:
    int isSelfdividing(int n){
        int number =n;
        while(number){
            int digit = number%10;
            if(digit==0||n%digit!=0){
                return false;
            }
            number/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(isSelfdividing(i)) ans.push_back(i);
        }
        return ans;
    }
};