class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int end1, end2;
        end1 = end2 = 0;
        int buy1, buy2;
        buy1 = buy2 = INT_MIN;
        for(int p : prices) {
            end2 = max(end2, buy2 + p);
            buy2 = max(buy2, end1 - p);
            end1 = max(end1, buy1 + p);
            buy1 = max(buy1, -p);
        }
        
        return end2;
    }
};