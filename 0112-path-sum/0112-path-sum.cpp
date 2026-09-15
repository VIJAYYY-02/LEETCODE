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
 */
class Solution {
public:
    bool Sum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return root->val == targetSum;

        int sum = targetSum - root->val;

        return Sum(root->left, sum) || Sum(root->right, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return Sum(root, targetSum);
    }
};