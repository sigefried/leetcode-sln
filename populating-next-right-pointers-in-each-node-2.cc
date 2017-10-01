/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *head = nullptr, *prev = nullptr;
        while (cur != nullptr) {
            //current level
            while (cur != nullptr) {
                if (cur->left) {
                    if (prev == nullptr) {
                        // first point
                        head = cur->left;
                    } else {
                        prev->next = cur->left;
                    }
                    prev = cur->left;
                }
                
                if (cur->right) {
                    if (prev == nullptr) {
                        head = cur->right;
                    } else {
                        prev->next = cur->right;
                    }
                    prev = cur->right;
                }
                cur = cur->next;
            }
            
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
    }
};