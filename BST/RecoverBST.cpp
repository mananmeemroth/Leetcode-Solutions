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

public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void helper(TreeNode* node){
        if(node==nullptr) return;
        helper(node->left);
        if(prev&& prev->val>node->val){
            if(first==nullptr) first=prev;
            second = node;
        }
        prev = node;
        helper(node->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
};

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        helper(root);
        // Swap the values of the two wrong nodes
        swap(first->val, second->val);
    }

    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;

        helper(node->right);
    }
};