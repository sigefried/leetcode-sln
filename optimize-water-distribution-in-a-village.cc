

class Solution {
public:
    vector<int> uf;

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        uf.resize(n + 1, 0);
        for (auto& p : pipes) swap(p[0], p[2]);
        for (int i = 0; i < n; ++i) {
            uf[i + 1] = i + 1;
            pipes.push_back({wells[i], 0, i + 1});
        }
        
        sort(pipes.begin(), pipes.end());
        
        
        int ans = 0;
        for (int i = 0; n > 0; ++i) {
            int x = find(pipes[i][1]), y = find(pipes[i][2]);
            if (x != y) {
                ans += pipes[i][0];
                uf[x] = y;
                --n;
            }
        }
        return ans;
        
    }
    
    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};