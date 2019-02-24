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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(root == nullptr) {
            return {nullptr, nullptr};
        } else if(root->val == V) {
            
            vector<TreeNode *> ret = {root, root->right};
            root->right = nullptr;
            return ret;
        } else if(root->val > V) {
            vector<TreeNode *> ret = splitBST(root->left, V);
            root->left = ret[1];
            ret[1] = root;
            return ret;
        } else {
            vector<TreeNode *> ret = splitBST(root->right, V);
            root->right = ret[0];
            ret[0] = root;
            return ret;
        }
    }

};