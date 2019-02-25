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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if(root->left == nullptr) {
                return root->right;
            } else if(root->right == nullptr) {
                return root->left;
            }
            root->val = get_min(root->right);
            root->right = delete_min(root->right);
            
        }
        return root;
    }
    
    int get_min(TreeNode *root) {
        while(root->left != nullptr) {
            root = root->left;
        }
        return root->val;
    }
    
    TreeNode* delete_min(TreeNode *root) {
        if(root->left == nullptr) return root->right;
        root->left = delete_min(root->left);
        return root;
        
    }
};