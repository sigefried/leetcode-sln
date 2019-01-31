/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*,RandomListNode*> copied;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        if(copied.count(head) > 0) {
            return copied[head];
        }
        
        RandomListNode *cp = new RandomListNode(head->label);
        copied[head] = cp;
        
        cp->next = copyRandomList(head->next);
        cp->random = copyRandomList(head->random);
        return cp;
    }
};
