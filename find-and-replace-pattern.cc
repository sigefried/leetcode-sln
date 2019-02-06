class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(auto w : words) {
            int l1 = w.size();
            int l2 = pattern.size();
            if(l1 != l2) continue;
            unordered_map<char, char> fwd, bck;
            bool valid = true;
            for(int i = 0; i < l1; ++i) {
                if(fwd.count(w[i])) {
                    if (fwd[w[i]] != pattern[i]) {
                        valid = false;
                        break;
                    }
                } else {
                    if(bck.count(pattern[i])) {
                        valid = false;
                        break;
                    }
                    fwd[w[i]] = pattern[i];
                    bck[pattern[i]] = w[i];
                }
            }
            if(valid) {
                ret.push_back(w);
            }
        }
        return ret;
    }
};