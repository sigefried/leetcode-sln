/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string ret;
        dfs(root, ret);
        return ret + " " + to_string(INT_MIN);
    }
    
    void dfs(Node *cur, string &s) {
        if(cur == nullptr) return;
        s += " " + to_string(cur->val) + " " + to_string((cur->children.size()));
        for(auto n : cur->children) {
            dfs(n, s);
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    Node * decode(stringstream &ss) {
        int cur;
        ss >> cur;
        if(cur == INT_MIN) return nullptr;
        auto root = new Node();
        root->val = cur;
        int sz;
        ss >> sz;
        for(int i = 0; i < sz; ++i) {
            root->children.push_back(decode(ss));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));