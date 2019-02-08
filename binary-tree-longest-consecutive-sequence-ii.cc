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
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ret;
    }
    //inc dec    
    pair<int, int> dfs(TreeNode *root) {
        if(root == nullptr) {
            return {0,0};
        }
        int inc = 1, dec = 1;
        auto lr = dfs(root->left);
        auto rr = dfs(root->right);
        if(root->left) {
            if(root->left->val - 1 == root->val) {
                inc = max(inc, lr.first + 1);
            } else if(root->left->val + 1 == root->val) {
                dec = max(dec, lr.second + 1);
            }
        }
        if(root->right) {
            if(root->right->val - 1 == root->val) {
                inc = max(inc, rr.first + 1);
            } else if(root->right->val + 1 == root->val) {
                dec = max(dec, rr.second + 1);
            }
        }
        ret = max(ret, inc + dec - 1);
        return {inc, dec};
    }
};