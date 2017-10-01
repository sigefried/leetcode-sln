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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return genTree(1, n);
    }
    vector<TreeNode *> genTree(int start, int end) {
        vector<TreeNode *> ret;
        if (start > end) {
            ret.push_back(nullptr);
            return ret;
        }
        if (start == end) {
            ret.push_back(new TreeNode(start));
            return ret;
        }
        
        vector<TreeNode *> left, right;
        for (int i = start; i <= end; ++i) {
            left = genTree(start,i-1);
            right = genTree(i+1,end);
            for (auto lnode : left) {
                for (auto rnode : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};