class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N,vector<bool>(N+1, false));
        dp[0][1] = true;
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff >= N || !dp[j][diff]) continue;
                dp[i][diff] = true;
                dp[i][diff - 1] = true;
                dp[i][diff + 1] = true;
                if(i == N - 1) return true;
            }
        }

        return false;
    }
};