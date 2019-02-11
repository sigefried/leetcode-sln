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
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        auto ret = dfs(root);
        return max(ret.first, ret.second);
    }
    // {include, exclude}
    pair<int, int> dfs(TreeNode *cur) {
        if(cur == nullptr) {
            return {0,0};
        }
        
        auto le = dfs(cur->left);
        auto re = dfs(cur->right);
        int include = le.second + re.second + cur->val;
        int exclude = max(le.first, le.second) + max(re.first, re.second); 
        return {include, exclude};
    }
};