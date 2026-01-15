#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int value){
        val = value;
        next = nullptr;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHt = checkHeight(root->left);
        if (leftHt == -1) return -1;

        int rightHt = checkHeight(root->right);
        if (rightHt == -1) return -1;

        if (abs(leftHt - rightHt) > 1) return -1;

        return 1 + max(leftHt, rightHt);
    }
};
