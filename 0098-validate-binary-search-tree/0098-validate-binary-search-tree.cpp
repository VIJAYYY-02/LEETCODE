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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

       
        if (root->left) {
            TreeNode* leftMax = findMax(root->left);
            if (leftMax->val >= root->val) return false;
        }

        
        if (root->right) {
            TreeNode* rightMin = findMin(root->right);
        if (rightMin->val <= root->val) return false;
        }

      
        return isValidBST(root->left) && isValidBST(root->right);
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node->right) node = node->right;
        return node;
    }
};
