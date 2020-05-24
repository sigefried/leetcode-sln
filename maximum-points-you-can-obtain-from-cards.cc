class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sz = n - k;
        int ws = 0;
        int total = 0;
        for(int i = 0; i < sz; ++i) {
            ws += cardPoints[i];
            total += cardPoints[i];
        }
        int mid = ws;
        for(int i = sz; i < cardPoints.size(); ++i) {
            ws += cardPoints[i] - cardPoints[i-sz];
            mid = min(mid, ws);
            total += cardPoints[i];
        }
        
        return total -mid;
    }
};