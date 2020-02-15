class DS {
public:
    
    map<int, int> parent;
    int cnt;
    
    void add(int x) {
        if(parent.count(x) == 0) {
            parent[x] = x;
            cnt++;
        }
    }
    
    bool contains(int x) {
        return parent.count(x) > 0;
    }
    
    DS() {
        cnt = 0;  
    }
    
    void merge(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if(px == py) return;
        parent[px] = py;
        cnt--;
    }
    
    int find_parent(int x) {
        if(parent[x] != x) {
            parent[x] = find_parent(parent[x]);
        }
        
        return parent[x];
    }
    
};


class Solution {
public:
    
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        DS ds;
        if(m <= 0 || n <=0) return ans;
        
        for(auto it : positions) {
            int x = it[0];
            int y = it[1];
            int id = x * n + y;
            ds.add(id);
            //cout<< ds.cnt << endl;
            //cout << x << ":" << y << ":" << id << endl;
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int nid = nx * n + ny;
                if (ds.contains(nid)) {
                    //cout << nx << "," << ny << "," << nid << endl;
                    ds.merge(id, nid);
                }
            }
            
            ans.push_back(ds.cnt);
        }
        return ans;
    }
    
};