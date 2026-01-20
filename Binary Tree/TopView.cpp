#include <iostream>
#include <map>
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
    vector<int> topView(TreeNode* root){
        
    }
};

// Class containing the logic for top view
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(TreeNode* root) {
        // Create a vector to store the final answer
        vector<int> ans;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return ans;
        }

        // Create a map to store vertical level -> node value (only first encountered)
        map<int, int> mpp;

        // Create a queue for BFS that stores {node, vertical_level}
        queue<pair<TreeNode*, int>> q;

        // Push the root node with vertical level 0
        q.push({root, 0});

        // Start BFS traversal
        while (!q.empty()) {
            // Extract the front element of the queue
            auto it = q.front();
            q.pop();

            // Get the node and its vertical position
            TreeNode* node = it.first;
            int line = it.second;

            // If this vertical position is being visited for the first time, store it
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->val;
            }

            // If there is a left child, push it with vertical level - 1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // If there is a right child, push it with vertical level + 1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map and store values in the answer vector
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        // Return the result
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
