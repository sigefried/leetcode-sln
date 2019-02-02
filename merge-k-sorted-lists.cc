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

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [] (const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp) > pq(cmp);
        ListNode *head = new ListNode(-1);
        for(auto l : lists) {
            if(l != nullptr )pq.push(l);
        }
        ListNode *p = head;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            p->next = cur;
            p = p->next;
            if(cur->next != nullptr) pq.push(cur->next);
            
        }
        
        return head->next;
    }
};