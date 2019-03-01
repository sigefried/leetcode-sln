// spfa
struct node {

    int x;
    int y;
    node(int x, int y) : x(x), y(y){};
};

class Solution {
public:
    int m, n;
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        if(m == 0) return -1;
        n = maze[0].size();
        if(n == 0) return -1;
        node st(start[0], start[1]);
        queue<node> q;
        q.push(st);
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        dist[start[0]][start[1]] = 0;
        visited[start[0]][start[1]] = 1;
        while(!q.empty()) {
            auto head = q.front(); q.pop();
            visited[head.x][head.y] = 0;
            for(int d = 0; d < 4; ++d) {
                vector<int> ret = go_end(maze, head.x, head.y, d);
                if(dist[ret[0]][ret[1]] > dist[head.x][head.y] + ret[2]) {
                    dist[ret[0]][ret[1]] = dist[head.x][head.y] + ret[2];
                    if(visited[ret[0]][ret[1]] == 0) {
                        visited[ret[0]][ret[1]] = 1;
                        node nxt(ret[0], ret[1]);
                        q.push(nxt);                        
                    }

                }
            }
        }
        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
    
    vector<int> go_end(vector<vector<int>>& maze, int x, int y, int d) {
        int nx = x, ny = y, step = 0;
        if(d == 0) {
            //left
            while(valid(maze,nx,ny)) {
                ny--;
                step++;
            }
            ny++;
        } else if(d == 1) {
            // up
            while(valid(maze,nx,ny)) {
                nx--;
                step++;
            }
            nx++;
        } else if(d == 2) {
            //right
            while(valid(maze,nx,ny)) {
                ny++;
                step++;
            }
            ny--;
        } else {
            //down
            while(valid(maze,nx,ny)) {
                nx++;
                step++;
            }
            nx--;
        }
        step--;
        return {nx, ny, step};
    }
    
    bool valid(vector<vector<int>>& maze, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == 0;
    }
};