class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) {
            return 0;
        }
        
        int lastR = costs[0][0];
        int lastG = costs[0][1];
        int lastB = costs[0][2];
        for(int i = 1; i < costs.size(); ++i) {
            int curR = min(lastG, lastB) + costs[i][0];
            int curG = min(lastR, lastB) + costs[i][1];
            int curB = min(lastR, lastG) + costs[i][2];
            lastR = curR;
            lastG = curG;
            lastB = curB;
        }
        
        
        return min({lastR, lastG, lastB});
    }
};