class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto &a, auto &b){
            return a.size() < b.size();
        });
        int ans = 0;
        unordered_map<string,int> dp;
        for(auto w : words) {
            for(int i = 0; i < w.size(); ++i) {
                dp[w] = max(dp[w], dp[w.substr(0,i) + w.substr(i+1)] +1);
            }
            ans = max(dp[w], ans);
        }
        
        return ans;
        
    }
};