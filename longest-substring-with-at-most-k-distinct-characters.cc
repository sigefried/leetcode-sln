class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> count(256,0);
        int bar = -1, distinct = 0, ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]]++ == 0) {
                distinct++;
            }
            while (distinct > k) {
                if (--count[s[++bar]] == 0) {
                    distinct--;   
                }
            }
            ret = max(ret, i - bar);
        }
        return ret;
    }
};