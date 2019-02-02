class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char,char> fwd;
        map<char,char> bck;
        for(int i = 0; i < s.size(); ++i) {
            if(fwd.count(s[i]) == 0) {
                if(bck.count(t[i]) && bck[t[i]] != s[i] ) return false;
                fwd[s[i]] = t[i];
                bck[t[i]] = s[i];
            } else {
                if(fwd[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};