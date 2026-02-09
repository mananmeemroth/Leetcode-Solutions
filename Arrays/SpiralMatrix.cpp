#include <iostream>
using namespace std;


class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();

        int visited = -200;

        vector<int> ans(m * n, 0);
        int direction = 0;
        int x = 0, y = 0;
        int cnt = 0;

        while(cnt < m * n) {
            ans[cnt] = matrix[x][y];
            matrix[x][y] = visited;
            cnt++;

            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] == visited) {
                direction = (direction + 1) % 4;
            }

            x += dx[direction];
            y += dy[direction];
        }

        return ans;
    }
};