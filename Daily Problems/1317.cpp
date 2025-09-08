#include <iostream>
using namespace std;
// this fails when the digits have "0" in between for ex: 5009,4007,etc;

class Solution {
    bool containszero(int p){
        if(p%10==0){
            return true;
        }else return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> arr(2);
        for(int i=1;i<=n/2;i++){
            int a = i;
            int b = n-i;
            if(!containszero(a)&&!containszero(b)){
                arr[0]=a;
                arr[1]= b;
            }
        }

        return arr;
    }

};

// best Solution
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check = [](int x) {
            while (x > 0) {
                if (x % 10 == 0) return false;
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i < n; ++i) {
            int j = n - i;
            if (check(i) && check(j)) {
                return {i, j};
            }
        }
        return {};
    }
};