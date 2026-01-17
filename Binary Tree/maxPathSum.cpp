#include <iostream>
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
private:
    int maxpathdown(TreeNode* node,int& res){
        if(!node) return 0;
        int leftsum=max(0,maxpathdown(node->left,res));
        int rightsum=max(0,maxpathdown(node->right,res));
        res=max(res,leftsum+rightsum+node->val);
        return max(leftsum,rightsum)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        maxpathdown(root,res);
        return res;
    }
};
