#include <iostream>
using namespace std;
class FindFloorCeil{
public:
    int findfloor(int arr[],int n,int x){
        int low =0;int high = n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]<=x){
                ans = arr[mid];
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    int findCeil(int arr[],int n,int x){
        int low =0;
        int high =n-1;
        int ans=arr[high];
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                high = mid-1;
                ans=high;
            }else{
                low=mid+1;
            }
        }return ans;
    }

    pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
        int f = findfloor(arr, n, x);
        int c = findCeil(arr, n, x);
        return make_pair(f, c);
    }
};
