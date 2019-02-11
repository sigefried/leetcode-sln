/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(dfs(head) == 0) return head;
        else {
            ListNode *newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
    }
    
    int dfs(ListNode *cur) {
        if(cur == nullptr) return 1;
        int carry = dfs(cur->next);
        int tmp = cur->val + carry;
        cur->val = tmp % 10;
        return tmp / 10;
    }
};