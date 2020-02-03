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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> result;
        
        set<int> to_delete_set(to_delete.begin(), to_delete.end());
        if(root == nullptr) return result;
        if(to_delete_set.find(root->val) == to_delete_set.end()) {
            result.push_back(root);
        }
        dfs(root, to_delete_set, result);
        return result;
    }
    
    TreeNode* dfs(TreeNode *root,set<int> &to_delete_set, vector<TreeNode *> &result) {
        if(root == nullptr) return root;
        
        if(to_delete_set.find(root->val) != to_delete_set.end()) {
            root->left = dfs(root->left, to_delete_set, result);
            root->right = dfs(root->right, to_delete_set, result);
            if(root->left != nullptr) {
                result.push_back(root->left);
            }
            if(root->right != nullptr) {
                result.push_back(root->right);
            }
            
            return nullptr;
        } else {
            root->left = dfs(root->left, to_delete_set, result);
            root->right = dfs(root->right, to_delete_set, result);
            return root;
        }
    }
};