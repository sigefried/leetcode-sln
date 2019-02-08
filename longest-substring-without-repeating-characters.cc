class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        int ret = 0, start = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(pos[s[i]] > start) {
                start = pos[s[i]];
            }
            pos[s[i]] = i;
            
            ret = max(ret, i - start);
        }
        return ret;
    }
};