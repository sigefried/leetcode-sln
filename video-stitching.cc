class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> dp(T+1, T+1);
        
        dp[0] = 0;
        for(int i = 1; i <= T; ++i) {
            for(auto c : clips) {
                if(i >= c[0] && i <= c[1]) {
                    dp[i] = min(dp[i], dp[c[0]]+1);
                }
            }
            
            if(dp[i] == T + 1) return -1;
        }
        
        return dp[T];
    }
};