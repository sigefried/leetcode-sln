class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int row = 0;
        int ret = 0;
        vector<int> cols(n, 0);
        if(n == 0) return 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 'W') continue;
                if(j == 0 || grid[i][j-1] == 'W') {
                    row = calc_row(grid, i, j);
                }
                
                if(i == 0 || grid[i-1][j] == 'W') {
                    cols[j] = calc_col(grid,i,j);
                }
                
                if(grid[i][j] == '0') {
                    ret = max(row + cols[j], ret);
                }
            }
        
        }
        return ret;
    }
    
    int calc_row(vector<vector<char>> &grid, int i, int j) {
        int ret = 0;
        int n = grid[0].size();
        while(j < n && grid[i][j] != 'W') {
            if(grid[i][j] == 'E') ret++;
            j++;
        }
        return ret;
    }
    
    int calc_col(vector<vector<char>> &grid, int i, int j) {
        int ret = 0;
        int m = grid.size();
        while(i < m && grid[i][j] != 'W') {
            if(grid[i][j] == 'E') ret++;
            i++;
        }
        return ret;
    }
};