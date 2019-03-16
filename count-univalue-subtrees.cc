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
    int ret = 0;
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return ret;
    }
    
    bool dfs(TreeNode *cur) {
        if(cur == nullptr) return true;
        auto l = dfs(cur->left);
        auto r = dfs(cur->right);
        
        if(l && r 
            && ((cur->left == NULL) || cur->left->val == cur->val)
            && ((cur->right == NULL) || cur->right->val == cur->val)
           ) {
            ++ret;
            return true;
        }
        return false;
    }
};