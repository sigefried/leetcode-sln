/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        TreeNode *pre = nullptr;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            ret.push_back(cur->val);
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
        }
        return ret;
    }
};