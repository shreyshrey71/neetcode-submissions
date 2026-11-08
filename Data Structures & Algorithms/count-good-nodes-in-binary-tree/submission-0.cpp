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
    int dfs(TreeNode* root, int m) {
        if (!root) return 0;
        int res = 0;
        if (root->val >= m) {
            res++;
            m = root->val;
        }
        return res + dfs(root->left, m) + dfs(root->right, m);
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};
