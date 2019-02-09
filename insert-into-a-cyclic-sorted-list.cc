/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            head = new Node(insertVal, nullptr);
            return head;
        }
        
        Node *prev = head;
        Node *next = head->next;
        bool flag = false;
        while(true) {
            
            if(prev->val <= insertVal && insertVal <= next->val ||  //insert in between
              prev->val > next->val && insertVal < next->val || 
              prev->val > next->val && insertVal > prev->val
              ) {
                prev->next = new Node(insertVal, next);
                flag = true;
                break;
            }
            
            prev = prev->next;
            next = next->next;
            if(prev == head) break;
        }
        
        if(!flag) {
            prev->next = new Node(insertVal, next);
        }
        return head;
    }
};