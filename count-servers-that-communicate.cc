class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<int> rows(m,0), cols(n,0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    ans++;
                }        
            }
        }
        return ans;
    }
};