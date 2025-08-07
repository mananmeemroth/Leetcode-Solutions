#include <iostream>
using namespace std;

// solution 1
class Solution { // with bitwise operator
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};
// solution 2
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n=A.size();
        
        if(n==1) return A[0];
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==0&& A[0]!=A[1]) return A[mid];
            if(mid==n-1&&A[n-1]!=A[n-2]) return A[mid];

            if(A[mid-1]!=A[mid]&&A[mid]!=A[mid+1]) return A[mid];

            if(mid%2==0){
                if(A[mid-1]==A[mid]){
                    end =mid-1;
                }else{start=mid+1;}
            }else{
                if(A[mid-1]==A[mid]){
                    start=mid+1;
                }else{end =mid+1;}
            }
        }
    }
};
//solution 3

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0];
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mid % 2 == 1) mid--;
            if (A[mid] == A[mid + 1]) start = mid + 2;
            else end = mid;
        }
        return A[start];
    }
};
