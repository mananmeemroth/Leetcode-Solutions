#include <iostream>
using namespace std;

//code 1
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor){
        if(sr<0 ||sr>= image.size() || sc<0 || sc >= image[0].size() || image[sr][sc]!=originalColor){
            return;
        }

        image[sr][sc]= newColor;

        dfs(image, sr + 1, sc, originalColor, newColor);
        dfs(image, sr - 1, sc, originalColor, newColor);
        dfs(image, sr, sc + 1, originalColor, newColor);
        dfs(image, sr, sc - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int originalColor = image[sr][sc];

        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }
        
        return image;
    }
};


// code 2

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColour, int delRow[], int delCol[], int initcolor) {
        ans[row][col] = newColour;
        int n = image.size();
        int m = image[0].size();
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initcolor && ans[nrow][ncol] != newColour) {
                dfs(nrow, ncol, ans, image, newColour, delRow, delCol, initcolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColour) {
        int initcolor = image[sr][sc];
        if (initcolor == newColour) {
            return image;
        }
        
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        dfs(sr, sc, ans, image, newColour, delRow, delCol, initcolor);
        
        return ans;
    }
};
