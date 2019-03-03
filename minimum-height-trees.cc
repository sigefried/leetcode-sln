class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        
        unordered_map<int, unordered_set<int>> neighbors;
        unordered_map<int, int> indegree;
        for(auto edge : edges) {
            neighbors[edge.first].insert(edge.second);
            neighbors[edge.second].insert(edge.first);
            indegree[edge.first]++;
            indegree[edge.second]++;
        }
        vector<int> leaf;
        unordered_set<int> visited;
        for(auto it : indegree) {
            if(it.second == 1) {
                leaf.push_back(it.first);
            }
        }
        while(visited.size() < n - 2) {
            vector<int> next_leaf;
            for(auto i : leaf) {
                visited.insert(i);
                for(auto j : neighbors[i]) {
                    if(visited.count(j)) continue;
                    indegree[j]--;
                    if(indegree[j] == 1) {
                        next_leaf.push_back(j);
                    }
                }
            }
            leaf = next_leaf;
        }
        
        return leaf;
    }
};