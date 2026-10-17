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
 */class Solution {
public:
    int tilt = 0;

    int dfs(TreeNode* node) { // depth first serach 
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        tilt += abs(left - right);/// abs works as mode (remove neg sign )

        return left + right + node->val;
    }

    int findTilt(TreeNode* root) {
        dfs(root);
        return tilt;
    }
};