/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        Node *cur = root, *head = nullptr, *prev = nullptr;
        while(cur != nullptr) {
            while(cur != nullptr) {
                if(cur->left) {
                    if(prev == nullptr) {
                        head = cur->left;
                    } else {
                        prev->next = cur->left;
                    }
                    prev = cur->left;
                }
                
                if(cur->right) {
                    if(prev == nullptr) {
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
        return root;
    }
};