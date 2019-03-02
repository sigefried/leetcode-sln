class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if(i  < n - 1) {
                dp[i][i+1] = (s[i] == s[i+1]);
            }
        }
        for(int i = 2; i < n; ++i) {
            for(int j = 0; j < i - 1; ++j) {
                dp[j][i] = (dp[j + 1][i - 1] && s[i] == s[j]);
                
            }
        }
        int max = 0;
        string maxstr = "";
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j] && j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};