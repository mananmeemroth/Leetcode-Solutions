#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:

    int reverse(int x1) {
        int r=0;
        while(x1){
            if(r<INT_MIN/10|| r>INT_MAX/10) return 0;
            r= r*10+x1%10;
            x1 = x1/10;
        }
        return r;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;

        int reversed = reverse(x);
        if(reversed==x){
            cout<<true<<endl;
        }else{
            cout <<false<<endl;
        }
    }
};

// better solution 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return reverse == xcopy;        
    }
};