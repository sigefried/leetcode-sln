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
    vector<TreeNode*> allPossibleFBT(int N) {
        return dfs(N);
    }
    
    vector<TreeNode *> dfs(int n) {
        vector<TreeNode *> ret;
        if(n == 1) {
            ret.push_back(new TreeNode(0));
        }
        if(n < 1 || n % 2 == 0) return ret;
        for(int i = 1; i < n; i += 2) {
            vector<TreeNode *> lret = dfs(i);
            vector<TreeNode *> rret = dfs(n-1-i);
            for(auto lch : lret) {
                for(auto rch : rret) {
                    TreeNode *r = new TreeNode(0);
                    r->left = lch;
                    r->right = rch;
                    ret.push_back(r);
                }
            }
        }
        return ret;
    }
};