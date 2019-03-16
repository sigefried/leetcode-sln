class Node {
public:
    Node(int x, int y, int height) {
        this->x = x;
        this->y = y;
        this->height = height;
    }
    
    int x, y, height;
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        auto cmp = [](Node &a, Node &b) {
            return a.height > b.height;
        };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        int m = heightMap.size();
        if(m == 0) return 0;
        int n = heightMap[0].size();
        if(n == 0) return 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            visited[i][0] = true;
            visited[i][n-1] = true;
            Node cur1(i, 0, heightMap[i][0]);
            Node cur2(i, n - 1, heightMap[i][n - 1]);
            pq.push(cur1);
            pq.push(cur2);
        }
        for(int j = 0; j < n; ++j) {
            visited[0][j] = true;
            visited[m-1][j] = true;
            Node cur1(0, j, heightMap[0][j]);
            Node cur2(m-1, j, heightMap[m-1][j]);
            pq.push(cur1);
            pq.push(cur2);
        }
        
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        
        int ret = 0;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            
            for(int d = 0; d < 4; ++d) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    ret += max(0, cur.height - heightMap[nx][ny]);
                    Node nxt(nx, ny, max(cur.height, heightMap[nx][ny]));
                    pq.push(nxt);
                }
            }
        }
        
        return ret;
    }
};