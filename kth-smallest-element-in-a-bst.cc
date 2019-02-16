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
    int cnt = 0;
    int ret = 0;
    int kthSmallest(TreeNode* root, int k) {
        
        dfs(root,k);
        return ret;
    }
    
    void dfs(TreeNode *cur, int k) {
        if(cur == nullptr) return;
        dfs(cur->left, k);
        cnt++;
        if(cnt == k) {
            ret = cur->val;
            return;
        }
        dfs(cur->right, k);
    }
};