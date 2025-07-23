#include <iostream> 
using namespace std;
class Solution {
public:
    bool searchinRows(vector<vector<int>>& matrix, int target, int row){
        int n = matrix[0].size();
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==matrix[row][mid]){
                return true;
            }else if(target<matrix[row][mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int startrow=0, endrow=m-1;
        while(startrow<=endrow){
            int midrow = startrow + (startrow-endrow)/2;
            if(target >= matrix[midrow][0]&& target<=matrix[midrow][n-1]){
                searchinRows(matrix, target, midrow);
            }else if(target>=matrix[midrow][n-1]){
                startrow = midrow+1;
            }else{
                endrow = midrow-1;
            }
        }return false;
        

        
    }
};