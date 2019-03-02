class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n+2, INT_MAX));
        for(int j = 1; j <= n; ++j) {
            dp[0][j] = A[0][j-1];
        }
       ;
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j <= n; ++j) {
                int min_prev = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]});
                dp[i][j] = min_prev + A[i][j-1];
            }
        }
        int ret = INT_MAX;
        for(int j = 1; j <= n; ++j) {
            ret = min(ret, dp[m-1][j]);
        }
        return ret;
    }
};