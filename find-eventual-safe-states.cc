class Solution {
public:
    unordered_map<int, int> state;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        for(int i = 0; i < n; ++i) {
            if(dfs(graph, i)) ans.push_back(i);
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, int cur) {
        if(state.count(cur) != 0) {
            return state[cur] == 1;
        }
        
        state[cur] = 2;
        for(auto &nxt : graph[cur]) {
            if(!dfs(graph,nxt)) return false;
        }
        
        state[cur] = 1;
        
        return true;
    }
};