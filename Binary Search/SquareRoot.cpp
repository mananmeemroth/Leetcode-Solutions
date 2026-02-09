#include <iostream>
using namespace std;
class Solution {
  public:
    int floorSqrt(int n) {
        if(n<2) return n;
        int left=1,right=n/2,ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(mid*mid<=n){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int nthRoot(int n, int m) {
    int root = round(pow(m, 1.0 / n));
    long long check = 1;

    for(int i = 0; i < n; i++)
        check *= root;

    if(check == m) return root;
    return -1;
}
};