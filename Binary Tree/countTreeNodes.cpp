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
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftcnt = countNodes(root->left);
        int rightcnt = countNodes(root->right);
        return leftcnt+rightcnt+1;
    }
};