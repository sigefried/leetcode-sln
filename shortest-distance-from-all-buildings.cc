class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int ret, round;
        round = 0;
        auto total = grid;
        for(int i = 0; i < m; ++i) {
            for(int j  = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    auto dist = grid;
                    dist[i][j] = 0;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for(int d = 0; d < 4; ++d) {
                            int nx = cur.first + dx[d];
                            int ny = cur.second + dy[d];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == round) {
                                grid[nx][ny]--;
                                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                                total[nx][ny] += dist[nx][ny];
                                q.push({nx, ny});
                            }
                        }
                    }
                    round--;
                }
            }
        }
        
        ret = INT_MAX;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == round && total[i][j] < ret) {
                    ret = total[i][j];
                }
            }
            cout << endl;
        }        
        return ret == INT_MAX ? -1 : ret;
    }
};