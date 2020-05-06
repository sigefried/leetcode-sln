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
    int left, right, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        int total = count(root);
        return max({left, right, total - left - right - 1}) > total / 2;
    }
    
    int count(TreeNode *cur) {
        if(cur == nullptr) return 0;
        int l = count(cur->left), r = count(cur->right);
        if(cur->val == val) {
            left = l, right = r;
        }
        return l + r + 1;
    }
};