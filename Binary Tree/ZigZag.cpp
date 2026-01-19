// 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> store;
            for(int i=0;i<n;i++){
                TreeNode* frontnode=q.front();
                store.push_back(frontnode->val);
                q.pop();
                if(frontnode->left) q.push(frontnode->left);
                if(frontnode->right) q.push(frontnode->right);
            }
            if(flag){
                ans.push_back(store);
            }else{
                reverse(store.begin(), store.end());
                ans.push_back(store);
            }
            flag=!flag;
        }
        return ans;
    }
};