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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int accu = 0;
        dfs(root, accu);
        return ret;
    }
    
    void dfs(TreeNode *cur, int accu) {
        accu = accu * 10 + cur->val;
        if(cur->left == nullptr && cur->right == nullptr) {
            ret += accu;
            return;
        }
        if(cur->left != nullptr) {
            dfs(cur->left, accu);
        }
        
        if(cur->right != nullptr) {
            dfs(cur->right, accu);
        }
        
    }
};