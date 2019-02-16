class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        if(ns > nt) {
            return isOneEditDistance(t,s); // 1st < 2nd
        }
        if(nt - ns > 1) {
            return false;
        }

        
        if(ns == nt) {
            int cnt = 0;
            for(int i = 0; i < ns; ++i) {
                if(s[i] != t[i]) cnt++;
            }
            return cnt == 1;
        } else {
            for(int i = 0; i < ns; ++i) {
                if(s[i] != t[i]) {
                    return s.substr(i) == t.substr(i+1);
                }
            }
            return true;
        }
    }
};