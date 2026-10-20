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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> t(2, 0);
        t[1] = k;
        dfs(root, t);
        return t[0];
    }
    void dfs(TreeNode* root, vector<int>& t) {
        if (!root) return;
        dfs(root->left, t);
        if (t[1] == 0) return;
        t[1]--;
        if (t[1] == 0) {
            t[0] = root->val;
            return;
        }
        dfs(root->right, t);
    }
};
