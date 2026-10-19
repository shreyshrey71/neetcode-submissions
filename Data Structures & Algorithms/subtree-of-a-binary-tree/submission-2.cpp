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
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    void serialize(TreeNode* root, string& res) {
        if (root == nullptr) {
            res += "$#";
            return;
        }

        res += "$";
        res += to_string(root->val);
        serialize(root->left, res);
        serialize(root->right, res);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        return serialized_root.contains(serialized_subRoot);
    }
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q)
    //         return true;
    //     else if (!p || !q)
    //         return false;
    //     return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // }
};
