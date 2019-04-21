// sln1 reverse check
class Trie {
public:
    vector<Trie *> child;
    bool end = false;
    Trie() {
        child = vector<Trie *>(26, nullptr);
    }
    void insert(string &word, int pos = 0) {
        if (pos == word.size()) end = true;
        else {
            auto idx = word[pos] - 'a';
            if (child[idx] == nullptr) {
                child[idx] = new Trie();
            }
            child[idx]->insert(word, pos + 1);
        }
    }
    
    bool r_check(string &word, int pos) {
        if(end || pos == -1) return end;
        auto idx = word[pos] - 'a';
        if(child[idx] == nullptr) return false;
        else {
            return child[idx]->r_check(word, pos - 1);
        }
    }
};

class StreamChecker {
public:
    Trie root;
    string tmp;
    StreamChecker(vector<string>& words) {
        for(auto w : words) {
            reverse(w.begin(), w.end());
            root.insert(w);
        }
    }
    
    bool query(char letter) {
        tmp += letter;
        return root.r_check(tmp, tmp.size() - 1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

//sln2: keep trie pointer

class Trie {
public:
    vector<Trie *> child;
    bool end = false;
    Trie() {
        child = vector<Trie *>(26, nullptr);
    }
    void insert(string &word, int pos = 0) {
        if (pos == word.size()) end = true;
        else {
            auto idx = word[pos] - 'a';
            if (child[idx] == nullptr) {
                child[idx] = new Trie();
            }
            child[idx]->insert(word, pos + 1);
        }
    }

};

class StreamChecker {
public:
    Trie root;
    vector<Trie *> cands;
    StreamChecker(vector<string>& words) {
        for(auto w : words) {
            root.insert(w);
        }
        cands.push_back(&root);
    }
    
    bool query(char letter) {
        vector<Trie *> next = { &root };
        bool ret = false;
        for (auto t : cands) {
            auto nt = t->child[letter - 'a'];
            if (nt != nullptr) {
                if (nt->end) {
                    ret = true;
                }
                next.push_back(nt);
            }
        }
        cands.swap(next);
        return ret;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */