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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        return dfs(preStart, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode *dfs(int &preStart,int inStart,int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if(preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode *cur = new TreeNode(preorder[preStart++]);
        if(inStart == inEnd) return cur;
        int idx = 0;
        for(int i = inStart; i <= inEnd; ++i) {
            if(inorder[i] == cur->val) {
                idx = i;
                break;
            }
        }
        cur->left = dfs(preStart, inStart, idx - 1, preorder, inorder);
        cur->right = dfs(preStart, idx + 1, inEnd, preorder, inorder);
        return cur;
    }
};