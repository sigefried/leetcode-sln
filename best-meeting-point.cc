class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        int m,n;
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        if(n == 0) return 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        return calc(rows) + calc(cols);
    }
    
    int calc(vector<int> & nums) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        int ret = 0;
        while(l < r) {
            ret += (nums[r--] - nums[l++]);
        }
        return ret;
    }
};