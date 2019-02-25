// dfs
class Solution {
public:
    
    map<int, set<int>> graph;
    set<int> visited;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            if(graph.count(x) > 0 && graph.count(y) > 0) {
                // x and y already visited
                visited.clear();
                if(dfs(graph, x, y)) return {x, y};
            }
            graph[x].insert(y);
            graph[y].insert(x);
        }
        return {-1,-1};
    }
    
    bool dfs(map<int, set<int>> & graph, int cur, int end) {
        if(visited.count(cur) > 0) return false;
        if(graph[cur].count(end) > 0) return true;
        visited.insert(cur);
        for(auto nxt : graph[cur]) {
            if(dfs(graph, nxt, end)) return true;
        }
        return false;
    }
};

// union find
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DS ds;
        for(auto edge : edges) {
            ds.init(edge[0]);
            ds.init(edge[1]);
            if(!ds.merge(edge[0],edge[1])) {
                return edge;
            }
        }
        
        return {-1, -1};
    }
};