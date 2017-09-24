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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calcRootMax(root, maxSum);
        return maxSum;
    }
    
    int calcRootMax(TreeNode *root, int& maxSum) {
        if (root == nullptr) return 0;
        int lMax = max(0,calcRootMax(root->left,maxSum));
        int rMax = max(0,calcRootMax(root->right, maxSum));
        maxSum = max(maxSum, root->val + lMax + rMax);
        return root->val + max(lMax, rMax);
    }
};