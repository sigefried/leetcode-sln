class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int prevMin = INT_MAX / 2;
        int ret = 0;
        for(auto n : prices) {
            if(n < prevMin) {
                prevMin = n;
            } else if(n > prevMin) {
                
                ret = max(ret, n - prevMin);
            }
        }
        return ret;
    }
};