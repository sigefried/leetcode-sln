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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        TreeNode *prev = nullptr;
        return isValid(root, prev);
    }
    
    bool isValid(TreeNode *cur, TreeNode *&prev) {
        if (cur == nullptr) return true;
        if (!isValid(cur->left, prev)) return false;
        if (prev != nullptr && prev->val >= cur->val) return false;
        prev = cur;
        if (!isValid(cur->right, prev)) return false;
        return true;
    }
};