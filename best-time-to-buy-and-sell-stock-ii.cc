class Solution {
public:
    int maxProfit(vector<int>& prices) {
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