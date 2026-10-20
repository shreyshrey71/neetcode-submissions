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
    // bfs
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> result;
    //     if (!root) return result;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         vector<int> level;
    //         int qsize = q.size();
    //         for (int i = 0; i < qsize; i++) {
    //             TreeNode* curr = q.front();
    //             q.pop();
    //             level.push_back(curr->val);
    //             if (curr->left) q.push(curr->left);
    //             if (curr->right) q.push(curr->right);
    //         }
    //         result.push_back(level);
    //     }
    //     return result;
    // }

    // dfs
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return result;
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        if (depth == result.size()) result.push_back(vector<int>());
        result[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
