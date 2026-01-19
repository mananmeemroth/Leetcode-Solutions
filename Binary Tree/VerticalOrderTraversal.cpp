#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int,map<int,vector<int>>> nodes;

    void dfs(TreeNode* root, int x,int y){
        if(!root) return;
        nodes[x][y].push_back(root->val);
        dfs(root->left,x-1,y+1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);   

        vector<vector<int>> ans;

        for (auto &p : nodes) {
            vector<int> col;

            for (auto &row : p.second) {
                sort(row.second.begin(), row.second.end());
                for (int v : row.second) {
                    col.push_back(v);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};