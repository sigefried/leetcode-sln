class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<vector<int>>> islands;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                vector<vector<int>> island;
                if(dfs(i,j,i,j, grid,m ,n ,island) ) {
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
    
    int delta[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0};

    bool dfs(int i0, int j0, int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& island) {
        if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] <= 0) return false;
        island.push_back({i - i0, j - j0});
        grid[i][j] *= -1;
        for (int d = 0; d < 4; d++) {
            dfs(i0, j0, i + delta[d][0], j + delta[d][1], grid, m, n, island);
        }
        return true;
    }
};