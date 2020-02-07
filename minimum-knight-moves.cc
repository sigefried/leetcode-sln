class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0) return 0;
        vector<vector<int>> dirs = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {-2, -1}, {-1, -2}};
        unordered_map<int, unordered_map<int,int>> visited;
        x = abs(x);
        y = abs(y);
        visited[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int cnt = 0;
        while(!q.empty()) {
            ++cnt;
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto it = q.front(); q.pop();
                for(auto d : dirs) {
                    int nx = it.first + d[0];
                    int ny = it.second + d[1];
                    if(nx == x && ny == y) {
                        return cnt;
                    }
                    if (nx > -3 && nx < 304 && ny > -3 && ny < 304 && visited[nx][ny] != 1) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
        
    }
};