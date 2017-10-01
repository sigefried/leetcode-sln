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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode *> stk;
        vector<int> ret;
        TreeNode *last = nullptr;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode *top = stk.top();
                if (top->right && last != top->right) {
                    cur = top->right;
                } else {
                    ret.push_back(top->val);
                    last = top;
                    stk.pop();
                }
            }
        }
        return ret;
    }
};