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
    map<TreeNode *, TreeNode *> parent;
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode *start = dfs(root, k);
        
        set<TreeNode *> visited;
        queue<TreeNode *> q;
        visited.insert(start);
        q.push(start);
        while(!q.empty()) {
            TreeNode *cur = q.front();q.pop();
            if(cur->left == nullptr && cur->right == nullptr) {
                //is leaf
                return cur->val;
            }
            
            if(cur->left != nullptr && visited.count(cur->left) == 0) {
                visited.insert(cur->left);
                q.push(cur->left);
            }
            
            if(cur->right != nullptr && visited.count(cur->right) == 0) {
                visited.insert(cur->right);
                q.push(cur->right);
            }
            if(parent.count(cur) > 0 && visited.count(parent[cur]) == 0) { 
                visited.insert(parent[cur]);
                q.push(parent[cur]);
            }
        }
        
        return -1;
    }
    
    TreeNode *dfs(TreeNode *root, int k) {
        if(root->val == k) return root;
        
        if(root->left != nullptr) {
            parent[root->left] = root;
            TreeNode *left = dfs(root->left, k);
            if(left != nullptr) return left;
        }
        
        if(root->right != nullptr) {
            parent[root->right] = root;
            TreeNode *right = dfs(root->right, k);
            if(right != nullptr) {
                return right;
            }
        }
        
        return nullptr;
    }
};