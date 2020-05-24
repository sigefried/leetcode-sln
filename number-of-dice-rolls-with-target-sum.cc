class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < d; ++i) {
            //d times
            vector<int> next(target + 1, 0);
            for(int j = 1; j <= f; ++j) {
                for(int k = j; k <= target; ++k) {
                    next[k] = (next[k] + dp[k-j]) % 1000000007; 
                }
            }
            swap(next, dp);
        
        }
        return dp[target];
    }
};