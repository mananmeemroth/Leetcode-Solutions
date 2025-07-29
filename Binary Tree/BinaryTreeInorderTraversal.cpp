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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        cout<<root->val<<" ";
        inorderTraversal(root->right);
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//  class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorder(root, res);
//         return res;        
//     }

// private:
//     void inorder(TreeNode* node, vector<int>& res) {
//         if (!node) {
//             return;
//         }
//         inorder(node->left, res);
//         res.push_back(node->val);
//         inorder(node->right, res);
//     }    
// };