class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n,""));
        for(int l = 0; l < n; ++l) {
            for(int i = 0; i < n - l; ++i) {
                int j = i + l;
                //string substr;
                string substr = s.substr(i, j - i + 1);
                //return "";
                if(j - i < 4) {
                    dp[i][j] = substr;
                } else {
                    dp[i][j] = substr;

                    for(int k = i; k<j;k++) {
                        if((dp[i][k] + dp[k+1][j]).length() < dp[i][j].length()){
                            dp[i][j] = dp[i][k] + dp[k+1][j];
                        }
                    }
                             
                    for(int k = 0; k < substr.size() / 2; ++k) {
                        string needle = substr.substr(0, k + 1);
 
                        if(substr.size() % needle.size() != 0) continue;
                        int times = substr.size() / needle.size();
                        string repeated = "";
                        for(int t = 0; t < times; ++t) {
                            repeated += needle;
                        }
                        if(repeated == substr) {
                            string ss = to_string(times) + "[" + dp[i][i+k] +"]";
                            if(ss.size() < dp[i][j].size()) {
                                dp[i][j] = ss;
                            }
                        }
                    }
                }
            }
        }
        //cout << dp[0][n/2 - 1] << endl;
        //cout << dp[n/2][n - 1] << endl;
        return dp[0][n-1];
    }
};