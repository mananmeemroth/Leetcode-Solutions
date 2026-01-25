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
    void preordertraversal(TreeNode* root,vector<int>& v){
        if(root==nullptr) return;
        v.push_back(root->val);
        preordertraversal(root->left,v);
        preordertraversal(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        preordertraversal(root,v);
        sort(v.begin(),v.end());
        return v[k-1];
    }
};

// you can choose this too 

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Variable to store the count of visited nodes
        int count = 0;
        int result = -1;  // Initialize result
        
        // In-order traversal (recursive approach)
        inOrderTraversal(root, k, count, result);
        
        return result;
    }

private:
    void inOrderTraversal(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;

        // Traverse left subtree
        inOrderTraversal(node->left, k, count, result);
        
        // Visit current node
        count++;
        if (count == k) {
            result = node->val;  // Store the kth smallest value
            return;  // No need to continue
        }
        
        // Traverse right subtree
        inOrderTraversal(node->right, k, count, result);
    }
};
