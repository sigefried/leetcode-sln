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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) return p;
        if (root == q) return q;
        return covers(root, p ,q);
    }
    
    TreeNode *covers(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == p) return p;
        if (root == q) return q;
        if (root == nullptr) return nullptr;
        TreeNode *left = covers(root->left, p, q);
        TreeNode *right = covers(root->right, p, q);
        if (left != nullptr && right != nullptr) return root;
        else if (left == nullptr) {
            return right;
        } else {
            return left;
        }
    }
};