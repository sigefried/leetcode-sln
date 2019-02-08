class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for(int i = 0 ; i < m - 1; ++i) {
            for(int j = i + 1; j < m; ++j) {
                int tmp = 0;
                for(int k = 0; k < n; ++k) {
                    if(grid[i][k] == 1 && grid[j][k] == 1){
                        tmp++;
                    }
                }
                if(tmp > 1) {
                    ret += tmp * (tmp - 1) / 2;
                }
            }
        }
        return ret;
    }
};