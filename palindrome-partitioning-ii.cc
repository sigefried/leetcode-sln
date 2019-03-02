class Solution {
public:
    vector<vector<bool>> isPal;
    int n;
    int minCut(string s) {
        n = s.size();
        if(n == 0) return 0;
        isPal = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);
        for(int j = 0; j < n; ++j) {
            dp[j] = j;
            for(int i = 0; i <= j; ++i) {
                if(s[j] == s[i] && ( (i + 1 > j - 1) || isPal[i+1][j-1])) {
                    isPal[i][j] = true;
                    if(i == 0) {
                        dp[j] = 0;
                    } else {
                        dp[j] = min(dp[j], dp[i-1] + 1);
                    }
                }
            }
        }
        return dp[n-1];
    }

};