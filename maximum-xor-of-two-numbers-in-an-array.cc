class TrieNode {
public:
    vector<TrieNode *> child = {nullptr, nullptr};    
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int x) {
        cout << "x:" << x << endl;
        //int t1 = (x >> 0) & 1;
        //int t2 = (x >> 1) & 1;
        //cout <<t1  << ": " << t2 << endl;
        TrieNode *cur = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            //cout << i << "," << bit << endl;
            if(cur->child[bit] == nullptr) {
                
                cur->child[bit] = new TrieNode();
            }
            cur = cur->child[bit];
        }
        //cout << "---------\n";
    }
    
    int getMaxXor(int x) {
        int curSum = 0;
        TrieNode *cur = root;
        //cout << "x: " << x << endl;
        for(int i = 31; i >= 0; --i) {
            int bit = (x >> i) & 1;
            //cout << "cur:" << i << endl;
            if(cur->child[bit^1] != nullptr) {
                //cout << "dif:" << i << endl;
                cur = cur->child[bit^1];
                curSum += 1 << i;
            } else {
                cur = cur->child[bit];
            }
        }
        //cout << curSum << endl;
        //cout << "---------" << endl;
        return curSum;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        Trie trie;
        
        for(auto n : nums) {
            trie.insert(n);
        }
        
        int ret = INT_MIN;
        
        for(auto n : nums) {
            ret = max(ret, trie.getMaxXor(n));
        }
        
        return ret;
        
    }
};