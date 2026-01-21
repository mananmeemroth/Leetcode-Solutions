#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root==nullptr) return ans;
        map<int,int> mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->val;
            }
            if(root->left!=nullptr) q.push({root->left,line-1});
            if(root->right!=nullptr) q.push({root->right,line+1});
        }
        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};

// Driver code
int main() {
    // Create the sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    // Create a Solution object
    Solution solution;

    // Get the top view
    vector<int> result = solution.topView(root);

    // Print the top view traversal
    cout << "Top View Traversal: ";
    for (auto node : result) {
        cout << node << " ";
    }
    return 0;
}
