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
    vector<int> pre, post;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre.swap(pre);
        this->post.swap(post);
        int preStart = 0;
        return dfs(preStart, 0, this->pre.size() - 1);
    }
    
    TreeNode* dfs(int& preStart, int postStart, int postEnd) {
        if(postStart > postEnd) return nullptr;
        TreeNode *cur = new TreeNode(pre[preStart++]);
        if(postStart == postEnd) return cur;
        int mid = postStart;
        for(;mid <= postEnd; ++mid) {
            if(post[mid] == pre[preStart]) {
                break;
            }
        }
        cur->left = dfs(preStart, postStart, mid);
        cur->right = dfs(preStart, mid + 1, postEnd - 1);
        return cur;
        
    }
};