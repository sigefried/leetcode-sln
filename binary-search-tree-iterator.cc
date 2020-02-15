/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    stack<TreeNode *> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = stk.top();
        stk.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    void pushAll(TreeNode *node) {
        for(; node != nullptr; stk.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */