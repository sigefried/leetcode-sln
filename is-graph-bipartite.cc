class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; ++i) {
            if(graph[i].size() > 0 && color[i] == -1) {
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for(auto e : graph[cur]) {
                        if(color[e] == -1) {
                            color[e] = 1 - color[cur];
                            q.push(e);
                        } else {
                            if(color[e] == color[cur]) return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};