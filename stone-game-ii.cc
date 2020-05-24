class Solution {
public:
    
    vector<int> sum;
    map<int, map<int,int>> memo;
    int stoneGameII(vector<int>& piles) {
        if(piles.empty()) return 0;
        int n = piles.size();
        sum = vector<int>(n, 0);
        sum[n-1] = piles[n-1];
        for(int i = n - 2; i >= 0; --i) {
            sum[i] = sum[i+1] + piles[i];
        }
        
        return dfs(piles, 0, 1);
    }
    
    int dfs(vector<int> &piles, int i, int m) {
        if(i >= piles.size()) return 0;
        if(2 * m >= piles.size() - 1) {
            return sum[i];
        }
        
        if(memo[i][m] != 0) return memo[i][m];
        
        // next turn min
        int nmin = INT_MAX;
        for(int x = 1; x <= 2 * m; ++x) {
            nmin = min(nmin, dfs(piles, i+x, max(m,x)));
        }
        
        memo[i][m] = sum[i] - nmin;
        return memo[i][m];
    }
};