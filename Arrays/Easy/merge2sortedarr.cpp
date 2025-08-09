#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=m-1;
        int k=n-1;
        for(int i=n+m-1;i>=0;i--){
            if(j >= 0 && (k < 0 || nums1[j] >= nums2[k])){
                nums1[i]=nums1[j];
                j--;
            }else{
                nums1[i]=nums2[k];
                k--;
            }
        }

    }
};
//solution 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};