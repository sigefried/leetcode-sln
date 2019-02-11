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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return ret;
        dfs(root);
        return ret - 1;
    }
    
    int dfs(TreeNode *cur) {
        if(cur == nullptr) return 0;
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        ret = max(left + right + 1, ret);
        return max(left,right) + 1;
    }
};