class DS {
public:
    map<int,int> parent;
    int cnt;
    DS() {
        this->cnt = 0;
    }
    
    void add(int x) {
        if(parent.count(x) == 0) {
            parent[x] = x;
            cnt++;
        }
    }
    
    bool merge(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if(px == py) {
            return false;
        }
        cnt--;
        parent[px] = py;
        return true;
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
    int removeStones(vector<vector<int>>& stones) {
        DS ds;
        int n = stones.size();
        for(auto it : stones) {
            ds.add(it[0]);
            ds.add(it[1] + 10000);
            ds.merge(it[0], it[1] + 10000);
        }
        
        return n - ds.cnt;
    }
};