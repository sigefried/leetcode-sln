/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    map<int, map<int, vector<int>>> tmp;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for(auto &it : tmp) {
            vector<int> tmp;
            for(auto &it2 : it.second) {
                for(auto n : it2.second) {
                    tmp.push_back(n);
                }
                
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    void dfs(TreeNode *cur, int x, int y) {
        if(cur == nullptr) return;
        tmp[x][y].push_back(cur->val);
        dfs(cur->left, x-1, y + 1);
        dfs(cur->right, x+1, y + 1);
    }
};