class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int bar = -1;
        int maxCnt = 0;
        int ret = 0;
        for(int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'A']++;
            maxCnt = max(maxCnt, cnt[s[i] - 'A']);
            while(i - bar - maxCnt > k) {
                cnt[s[++bar] - 'A']--;
                for(auto freq : cnt) {
                    maxCnt = max(maxCnt, freq);
                }
            }
            ret = max(ret, i - bar);
        }
        return ret;
    }
};