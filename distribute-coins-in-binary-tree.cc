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
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ret;
    }
    
    int dfs(TreeNode *cur) {
        if(cur == nullptr) return 0;
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        ret += (abs(left) + abs(right));
        
        int remain = left + right - 1 + cur->val;
        return remain;
    }
};