class Solution {
public:
    int dx[2] = {-1, 1};
    int dy[2] = {1, -1};
    int m,n;
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        vector<int> ret;
        if(m == 0) return ret;
        n = matrix[0].size();
        if(n == 0) return ret;
        int p = 0;
        int total = m * n;
        
        int x = 0, y = 0;
        for(int i = 0; i < total; ++i) {
            ret.push_back(matrix[x][y]);
            x = x + dx[p];
            y = y + dy[p];
            
            if(!valid(x, y)) {
                p = (p + 1) % 2;
                if(x >= m) {
                    x = m - 1;
                    y += 2;
                }
                if( y >= n) {
                    y = n - 1;
                    x += 2;
                }
                if ( x < 0 ) {
                    x = 0;
                }
                if( y < 0) {
                    y = 0;
                }

            }
        }
        return ret;
    }
    
    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
};