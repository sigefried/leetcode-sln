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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0), *prev = dummy, *cur;
        dummy->next = head;
        for(int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }
        ListNode *start = prev->next;
        ListNode *next = start->next;
        for(int i = 0; i < n - m; ++i) {
            start->next = next->next;
            next->next  = prev->next;
            prev->next = next;
            next = start->next;
        }
        return dummy->next;
    }
};