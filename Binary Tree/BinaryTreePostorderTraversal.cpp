#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val =x;
        left = right=nullptr;
    }

};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }

    void postorder(TreeNode* node,vector<int>&res){
        if(!node){
            return;
        }

        postorder(node->left,res);
        postorder(node->right,res);
        res.push_back(node->val);
    }
};