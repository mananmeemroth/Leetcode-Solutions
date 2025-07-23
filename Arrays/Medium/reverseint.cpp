#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r=0;
        while(x){
            if(x<INT_MIN|| x>INT_MAX) return 0;
            r= r*10+x%10;
            x = x/10;
        }
        return r;
    }
};