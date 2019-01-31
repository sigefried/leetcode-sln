class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt;
        for(auto ch : t) {
            cnt[ch]++;
        }
        int total = t.size();
        int mc = 0;
        int bar = -1;
        string ret = s + "#";
        for(int i = 0; i < s.size(); ++i) {
            // 1 - > 0 extend  < 0 means too many chars
            if(--cnt[s[i]] >= 0) {
                mc++;
            }
            while (mc == total) {
                int len = i - bar;
                string sub = s.substr(bar + 1, len);
                if(sub.size() < ret.size()) {
                    ret = sub;
                }
                // shrink 0 > 1
                if(++cnt[s[++bar]] > 0 ) {
                    mc--;
                }
            }             
        }
        
        
        return ret == s + "#" ? "" : ret;
    }
};