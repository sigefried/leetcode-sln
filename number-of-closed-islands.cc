class Solution {
public:
    
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0, 1, 0, -1};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    dfs(grid, i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) { 
                if(grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
        
    }
    
    void dfs(vector<vector<int>>& g, int x, int y) {
        if (x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] == 1)
            return;
        
        g[x][y] = 1;
        for(int d = 0; d < 4; ++d) {
            dfs(g, x + dx[d], y + dy[d]);
        }
    }
};