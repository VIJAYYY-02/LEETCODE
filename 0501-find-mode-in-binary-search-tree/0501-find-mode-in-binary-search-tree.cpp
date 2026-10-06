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
public: // frquency ke liye map ,,,,,,second par freq and first par element
    void traverse(TreeNode* root, unordered_map<int,int>& freq) {
        if (!root) return;
        freq[root->val]++;              
        traverse(root->left, freq);     
        traverse(root->right, freq);    
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        traverse(root, freq);

        int maxFreq = 0;
        for (auto& p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        vector<int> modes;
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                modes.push_back(p.first);
            }
        }

        return modes;
    }
};
