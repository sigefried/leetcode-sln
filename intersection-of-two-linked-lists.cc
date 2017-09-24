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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) return nullptr;
        if (headB == nullptr) return nullptr;
        ListNode* p1 = headA;
        while (p1->next) p1 = p1->next;
        p1->next = headA;
        ListNode *slow = headB, *fast = headB;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr) {
            p1->next = nullptr;
            return nullptr;
        }
        slow = headB;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        
        p1->next = nullptr;
        return slow;
    }
};

// more elegant Solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) return nullptr;
        if (headB == nullptr) return nullptr;
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while (l1 != l2) {
            l1 = l1 == nullptr ? headB : l1->next;
            l2 = l2 == nullptr ? headA : l2->next;
        }
        return l1;
    }
};