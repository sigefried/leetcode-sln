/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        do_serialize(root, ret);
        return ret;
    }
    
    void do_serialize(TreeNode *root, string &out) {
        if(root == nullptr) {
            out += "# ";  
        } else {
            out = out + to_string(root->val) + " ";
            do_serialize(root->left, out);
            do_serialize(root->right, out);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    TreeNode* deserialize(istringstream& in) {
        string cur;
        in >> cur;
        if(cur == "#") {
            return nullptr;
        }
        TreeNode *r = new TreeNode(stoi(cur));
        r->left = deserialize(in);
        r->right = deserialize(in);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));