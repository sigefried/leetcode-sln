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
    set<int> target;
    vector<TreeNode*> ret; 
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i : to_delete) {
            target.insert(i);
        }
        if(target.find(root->val) == target.end()) {
            ret.push_back(root);
        }
        dfs(root);
        return ret;
    }
    void dfs(TreeNode * cur) {
        if(cur == nullptr) return;
        if (target.find(cur->val) == target.end()) {
            //no delete, need to check child to disconnect
            if(cur->left && target.find(cur->left->val) != target.end()) {
                dfs(cur->left);
                cur->left = nullptr;
            } else {
                dfs(cur->left);
            }
            if(cur->right && target.find(cur->right->val) != target.end()) {
                dfs(cur->right);
                cur->right = nullptr;
            } else {
                dfs(cur->right);
            }
        } else {
            // need to delete
            if(cur->left && target.find(cur->left->val) == target.end()) {
                //cout << "left" cur->left->val << endl;
                ret.push_back(cur->left);
            }
            if(cur->right && target.find(cur->right->val) == target.end()) {
                //cout << cur->right->val << endl;
                ret.push_back(cur->right);
            }
            dfs(cur->left);
            dfs(cur->right);
        } 
        
       
    }
};