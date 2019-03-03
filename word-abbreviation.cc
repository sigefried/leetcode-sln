class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> ret(n);
        vector<int> prefix(n);
        for(int i = 0; i < n; ++i) {
            prefix[i] = 1;
            ret[i] = makeAbbr(dict[i], 1);
            //cout << ret[i] << endl;
        }
        for(int i = 0; i < n; ++i) {
            while(true) {
                set<int> dup;
                for(int j = i + 1; j < n; ++j) {
                    if(ret[j] == ret[i]) {
                        dup.insert(j);
                    }
                }
                if(dup.empty()) break;
                dup.insert(i);
                for(int p : dup) {
                    ret[p] = makeAbbr(dict[p], ++prefix[p]);
                }
            }
        }
        return ret;
    }
    
    string makeAbbr(string s, int k) {
        if(k >= s.size() - 2) return s;
        
        string ret = s.substr(0, k) + to_string(s.size() - 1 - k) + s.substr(s.size() - 1);
        return ret;
    }
};