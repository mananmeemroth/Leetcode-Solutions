#include <iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    bool valid(TreeNode* node,long minimum, long maximum){
        if(node==nullptr) return true;
        if(node->val<=minimum||node->val>=maximum) return false;
        return valid(node->left,minimum,node->val) && valid(node->right,node->val,maximum);
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN,LONG_MAX);
    }
};