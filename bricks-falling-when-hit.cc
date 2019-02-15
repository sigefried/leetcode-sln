// sln1
class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<int>> g;
    vector<vector<int>> visited;
    int mark = 0;
    int m,n;
    bool valid(int x,int y){
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size(),n = grid[0].size();
        g.swap(grid);
        visited = vector<vector<int>>(220, vector<int>(220, 0));
        
        vector<int> ret;
        for(auto h : hits) {
            int x = h[0];
            int y = h[1];
            int remove = 0;
            
            if(g[x][y] == 1) {
                g[x][y] = 0;
                for(int d = 0; d<4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(!valid(nx, ny) || g[nx][ny] == 0) continue;
                    mark++;
                    
                    bool is_falling = falling(nx, ny);
                    
                    if(is_falling) {
                        remove += do_remove(nx, ny);
                    }
                }
            }
            
            ret.push_back(remove);
        }
        
        return ret;
    }
    
    bool falling(int x, int y) {
        if(!valid(x, y) || g[x][y] == 0) return true;
        if(visited[x][y] == mark) return true;
        if(x == 0) return false;
        visited[x][y] = mark;
        for(int d = 0; d<4; d++) {
            if (!falling(x + dx[d], y + dy[d])) {
                return false;
            }
        }
        return true;
    }
    
    int do_remove(int x, int y) {
        if(!valid(x, y) || g[x][y] == 0) return 0;
        g[x][y] = 0;
        int ret = 1;
        for(int d = 0; d<4; d++) {
            ret += do_remove(x + dx[d], y + dy[d]);
        }
        
        return ret;
    }
};

// sln2

class DS {
public:
    vector<int> parent;
    vector<int> size;
    DS(int len) {
        parent.push_back(0);
        size.push_back(0);
        for (int i = 1; i < len; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
        
    int find_parent(int x) {
        if(parent[x] != x) {
            parent[x] = find_parent(parent[x]);
        }
        return parent[x];
    }
    void merge(int a, int b) {
        int rootA = find_parent(a);
        int rootB = find_parent(b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }
    
};

class Solution {
public:
    DS* ds;
    int m,n;
    vector<vector<int>> g;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size();
        n = grid[0].size();
        ds = new DS(m*n + 1);
        vector<int> ret(hits.size(), -1);
        g.swap(grid);
        
        for(auto h : hits) {
            if (g[h[0]][h[1]] == 1) {
                g[h[0]][h[1]] = 2;
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(g[i][j] == 1) {
                    merge_around(i,j);
                }
            }
        }
        
        int old_cnt = ds->size[ds->find_parent(0)];
        for(int i = hits.size() - 1; i >= 0; --i) {
            int cx = hits[i][0];
            int cy = hits[i][1];
            if (g[cx][cy] == 2) {
                g[cx][cy] = 1;
                merge_around(cx, cy);
            }
            int cur_cnt = ds->size[ds->find_parent(0)];
            int diff = cur_cnt - old_cnt;
            ret[i] = diff > 0 ? diff - 1 : 0;
            old_cnt = cur_cnt;
        }
        
        delete ds;
        return ret;
    }
    
    int id(int x, int y) {
        return x * n + y + 1;
    }

    bool valid(int x,int y){
        return 0 <= x && x < m && 0 <= y && y < n;
    }
    void merge_around(int x, int y) {
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(valid(nx, ny) && g[nx][ny] == 1 ) {
                ds->merge(id(x,y), id(nx,ny));
            }
        }
        if(x == 0) {
            ds->merge(0, id(x,y));
        }
    }
};