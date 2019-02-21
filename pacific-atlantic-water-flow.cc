class Solution {
public:
    int m,n;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ret;
        m = matrix.size();
        if(m == 0) return ret;
        n = matrix[0].size();
        if(n == 0) return ret;
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        auto atlantic = pacific;
        
        for(int i = 0; i< m; ++i) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n-1);
        }
        
        
        for(int i = 0; i < n; ++i) {
            dfs(matrix, pacific, INT_MIN, 0, i);
            dfs(matrix, atlantic, INT_MIN, m-1, i);            
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>> &visitable, int prev, int x, int y) {
        //cout << x << " " <<  y << "," << prev << endl; 
        if(x < 0 || y < 0 || x >=m || y >=n || visitable[x][y] || matrix[x][y] < prev ) {
            return;
        }
        visitable[x][y] = true;
        for(int d = 0; d < 4; ++d) {
            dfs(matrix, visitable, matrix[x][y], x + dx[d], y + dy[d]);
        }
    }
    
    
};