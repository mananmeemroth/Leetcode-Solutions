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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            double sum = 0;

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            ans.push_back(sum / s); // average of this level
        }

        return ans;
    }
};
