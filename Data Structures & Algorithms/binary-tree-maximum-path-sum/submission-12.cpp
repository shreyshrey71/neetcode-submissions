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
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int lmax = dfs(root->left, res);
        int rmax = dfs(root->right, res);
        res = max(res, root->val);
        res = max(res, root->val + lmax + rmax);
        return max(root->val, root->val + max(lmax, rmax));
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        int rootMax = dfs(root, res);
        return max(rootMax, res);
    }
};
