class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size();
        vector<int> last(26, 0);
        int mod = 1e9 + 7;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = 0; j < 26; ++j) {
                sum  = (sum + last[j]) % mod;
            }
            last[S[i] - 'a'] = sum + 1;
        }
        int ret = 0;
        for(auto n : last) {
            ret = (ret + n) % mod;
        }
        return ret;
    }
};