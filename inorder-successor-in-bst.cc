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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr) return nullptr;
        return dfs(root,p);
    }
    TreeNode *dfs(TreeNode *root, TreeNode *p) {
        if(root == nullptr) return nullptr;
        if(root->val <= p->val) {
            return dfs(root->right , p);
        }
        
        TreeNode *sub = dfs(root->left, p);
        if(sub == nullptr) return root;
        else {
            return sub;
        }
    }
};