#include <iostream>
#include <queue>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxWidth=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int levelsize=q.size();
            int startidx=q.front().second;
            int endidx=q.back().second;
            maxWidth=max(maxWidth,endidx-startidx+1);
            for(int i=0;i<levelsize;i++){
                auto current =q.front();
                q.pop();
                TreeNode* node = current.first;
                int idx=current.second-startidx;
                if (node->left != NULL) {
                    q.push({node->left, 2 * idx + 1});
                }
                if (node->right != NULL) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }
        return maxWidth;
    }
};