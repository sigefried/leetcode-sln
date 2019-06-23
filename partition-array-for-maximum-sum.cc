class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            int curMax = 0;
            for(int k = 1; k <= K && i - k + 1 >= 0; ++k ) {
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i-k] : 0) + curMax * k);
            }
        }
        return dp[n-1];
    }
};