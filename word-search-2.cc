class TrieNode {
public:
    vector<TrieNode *> child;
    bool isWord;
    TrieNode() {
        child = vector<TrieNode *>(26,nullptr);
        isWord = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode *cur = root;
        for (auto c : s) {
            int id = c - 'a';
            if (cur->child[id] == nullptr) {
                cur->child[id] = new TrieNode();
                cur = cur->child[id];
            } else {
                cur = cur->child[id];
            }
        }
        cur->isWord = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto word : words) {
            trie.insert(word);
        }
        unordered_set<string> ret;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                findWords(board, x, y, trie.root, "", ret);
        
        return vector<string>(ret.begin(),ret.end());
        
    }
    
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, unordered_set<string>& result){
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
        
        if (root->child[board[x][y] - 'a'] != nullptr) {
            root = root->child[board[x][y] - 'a'];
            word.push_back(board[x][y]);
            if (root->isWord == true) {
                result.insert(word);
            }
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);

            
            board[x][y] = c;
        }
    }
    
};