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
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto [li, le] = dfs(root->left);
        auto [ri, re] = dfs(root->right);
        return {max(1 + le + re, max(li, ri)), 1 + max(le, re)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto [roi, roe] = dfs(root);
        return max(roi, roe) - 1;
    }
};
