class DS {
public:
    map<int, int> parent;
    
    DS () {};
    
    void init(int x) {
        if(parent.count(x) == 0) {
            parent[x] = x;
        }
    }
    
    int find_parent(int x) {
        if(parent[x] != x) {
            parent[x] = find_parent(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int x, int y) {
        int fx = find_parent(x);
        int fy = find_parent(y);
        if(fx == fy) return false;
        parent[fx] = fy;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), candA, candB;
        for(auto &edge : edges) {
            if(parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = -1;
            }
        }
        
        DS ds;
        for(auto &edge : edges) {
            if(edge[1] == -1) continue;
            ds.init(edge[0]);
            ds.init(edge[1]);
            if(!ds.merge(edge[0],edge[1])) {
                if(candA.size() != 0) return candA;
                else return edge;
            }
        }
        return candB;
    }
};