class DS {
public:
    map<int, int> parent;
    DS() {}  
    
    void add(int i) {
        if(parent.count(i) == 0) {
            parent[i] = i;
        }
    }
    
    int find_parent(int x) {
        if(parent[x] != x) {
            parent[x] = find_parent(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if(px == py) return false;
        parent[px] = py;
        return true;
    }
    
    int size() {
        int ret = 0;
        for(auto it : parent) {
            if(it.first == it.second) ret++;
        }
        return ret;
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        DS ds;
        for(int i = 0; i < n; ++i) {
            ds.add(i);
        }
        for(auto e : edges) {
            if(ds.merge(e.first, e.second) == false) return false;
        }
        return ds.size() == 1;
    }
};