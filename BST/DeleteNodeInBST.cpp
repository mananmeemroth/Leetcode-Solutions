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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }else{
            if(root->left==nullptr&&root->right==nullptr) return nullptr;
            if(root->left==nullptr) return root->right;
            if(root->right==nullptr) return root->left;
            // case 3:2 children
            TreeNode* temp=root->left;
            while(temp->right!=nullptr){
                temp=temp->right;
            }
            root->val = temp->val;
            root->left=deleteNode(root->left,temp->val);
        }
        return root;
    }
};


// // Case 3: Node has two children
// // We cannot delete the node directly because it would break the BST structure.
// // So we replace the node's value with its inorder predecessor.

// // Inorder predecessor = largest value in the left subtree
// // (rightmost node of the left subtree)

// TreeNode* temp = root->left;   // Move to left subtree

// // Find the maximum value in the left subtree
// while (temp->right != nullptr) {
//     temp = temp->right;
// }

// // Copy the predecessor's value into the current node
// root->val = temp->val;

// // Now delete the duplicate predecessor node from the left subtree
// // This recursive call will fall into case 1 or case 2 (easy deletion)
// root->left = deleteNode(root->left, temp->val);
