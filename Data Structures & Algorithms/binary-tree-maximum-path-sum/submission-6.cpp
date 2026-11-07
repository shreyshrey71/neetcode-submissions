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
    pair<int, int> dfs(TreeNode* root, int& res) {
        if (!root) return {-1e9, -1e9};
        auto [li, le] = dfs(root->left, res);
        auto [ri, re] = dfs(root->right, res);
        res = max(res, max(root->val, max(max(li, le), max(ri, re))));
        return {root->val + le + re, max(root->val, root->val + max(le, re))};
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e9;
        auto [roi, roe] = dfs(root, res);
        return max(max(roi, roe), res);
    }
};
