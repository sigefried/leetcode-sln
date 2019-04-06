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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for(int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        ListNode *slow = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        while(fast != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        prev->next = slow->next;
        return dummy->next;
    }
};