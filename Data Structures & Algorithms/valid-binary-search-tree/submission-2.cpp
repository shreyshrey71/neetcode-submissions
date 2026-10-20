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
        return dfs(root, INT_MIN, INT_MAX);
    }
    bool dfs(TreeNode* root, int lower_bound, int upper_bound) {
        if (!root) return true;
        return (lower_bound < root->val) && (root->val < upper_bound) &&
               dfs(root->left, lower_bound, root->val) && dfs(root->right, root->val, upper_bound);
    }
};
