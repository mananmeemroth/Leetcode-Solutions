#include <iostream>
#include <unordered_set>
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
    unordered_set<int> seen;

    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        if(seen.count(k-root->val)) return true;
        seen.insert(root->val);
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};

class Solution {
public:
    vector<int> ans;
    void Traversal(TreeNode* root){
        if(!root) return;
        Traversal(root->left);
        ans.push_back(root->val);
        Traversal(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        Traversal(root);
        int i = 0;
        int j = ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j] == k){
                return true;
            }
            if(ans[i]+ans[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};