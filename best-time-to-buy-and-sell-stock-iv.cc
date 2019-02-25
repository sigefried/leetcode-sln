class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n / 2 <= k) {
            return maxProfit2(prices);
        }
        vector<int> buy(k + 1, INT_MIN);
        vector<int> end(k + 1, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = k; j > 0; --j) {
                end[j] = max(end[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], end[j - 1] - prices[i]);
            }
        }
        return end[k];
    }
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        int ret = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(prices[i+1] - prices[i] > 0) {
                ret += (prices[i+1] - prices[i]);
            }
        }
        return ret;
    }
};