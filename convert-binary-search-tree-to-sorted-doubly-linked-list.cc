/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        Node * head = new Node(-1, nullptr, nullptr);
        Node *prev = head;
        dfs(root, prev);
        head->right->left = prev;
        prev->right = head->right;
        return head->right;
    }
    
    void dfs(Node *cur, Node* &prev) {
        if(cur == nullptr) return;
        dfs(cur->left, prev);
        prev->right = cur;
        cur->left = prev;
        prev = cur;
        dfs(cur->right, prev);
    }
    
    
};