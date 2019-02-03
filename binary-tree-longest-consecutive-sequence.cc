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
    int ret  = 0;
    int dfs(TreeNode *cur) {
        if(cur == nullptr) {
            return 0;
        }
        
        int cm = 1;
        int left = dfs(cur->left);
        if(cur->left && cur->left->val - 1 == cur->val) {
            cm = 1 + left;
        }
        int right = dfs(cur->right);

        if(cur->right && cur->right->val - 1 == cur->val) {
            cm = max(cm, 1+right);
        }
        ret = max(ret,cm);
        return cm;
        
    }
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return ret;
        dfs(root);
        return ret;
    }
};