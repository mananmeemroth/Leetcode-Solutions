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
    int heightofBT(TreeNode* root){
        if(root==nullptr) return 0;
        int heightleft = heightofBT(root->left);
        int heightright = heightofBT(root->right);
        return max(heightleft,heightright)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int length = heightofBT(root->left)+heightofBT(root->right);
        int dleft = diameterOfBinaryTree(root->left);
        int dright = diameterOfBinaryTree(root->right);
        return max(dleft,max(dright,length));
    }
};

// Optimized solution

class Solution {
public:
    int heightofBT(TreeNode* root){
        if(root==nullptr) return 0;
        int heightleft = heightofBT(root->left);
        int heightright = heightofBT(root->right);
        int ans = max(heightleft+heightright,ans);
        // return max(heightleft,heightright)+1;
        return ans;
    }

    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //     int length = heightofBT(root->left)+heightofBT(root->right);
    //     int dleft = diameterOfBinaryTree(root->left);
    //     int dright = diameterOfBinaryTree(root->right);
    //     return max(dleft,max(dright,length));
    // }
};