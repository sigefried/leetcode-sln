class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return r_break(s,dict);
    }
    
    vector<string> concat(string head, vector<string> rest) {
        for (int i = 0; i < rest.size(); ++i) {
            rest[i] = head + " " + rest[i];
        } 
        return rest;
    }
    
    vector<string> r_break(string s, unordered_set<string> &dict) {
        if (m.count(s)) return m[s];
        vector<string> ret;
        if (dict.count(s) > 0) {
            ret.push_back(s);
        }
        for (int len = 1; len < s.size(); ++len) {
            string head = s.substr(0,len);
            if (dict.count(head) > 0) {
                string rem = s.substr(len);
                vector<string> tmp = concat(head, r_break(rem,dict));
                ret.insert(ret.end(),tmp.begin(),tmp.end());
            }
        }
        m[s] = ret;
        return ret;
    }
};