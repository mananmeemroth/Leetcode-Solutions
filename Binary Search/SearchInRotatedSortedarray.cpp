// approach: first we will find the mid and then check
// if the right array ya fir left array is sorted or not(because one side will be sorted)
// but(how to find right ya fir left side is sorted????
//      --- we will check that start is less then mid(in case of right sorted) and vice versa for left side)
// and then go on the sorted side and apply binary search there

#include <iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& A, int target) {
        int st=0,end=A.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(A[mid]==target){
                return mid;
            }
            if(A[st]<=A[mid]){//right sorted
                if(A[st]<=target&&target<=A[mid]){
                    end =mid-1;
                }else{
                    st=mid+1;
                }
            }else{//left sorted
                if(A[mid]<=target&&target<=A[end]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};