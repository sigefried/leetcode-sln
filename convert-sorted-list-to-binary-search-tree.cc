/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }
        ListNode *fast = head, *slow = head;
        ListNode *next_head = nullptr, *pre_tail = nullptr;
        while (fast && fast->next) {
            pre_tail = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (pre_tail) pre_tail->next = nullptr;
        next_head = slow->next;
        TreeNode *cur = new TreeNode(slow->val);
        cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(next_head);
        return cur;
    }
};