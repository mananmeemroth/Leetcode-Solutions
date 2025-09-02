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
    TreeNode* findSubtreeMin(TreeNode* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            // Case 1: Node has no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            // Case 2A: Node has only right child
            else if (root->left == nullptr) {
                return root->right;
            }
            // Case 2B: Node has only left child
            else if (root->right == nullptr) {
                return root->left;
            }
            // Case 3: Node has both children
            else {
                TreeNode* successor = findSubtreeMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};