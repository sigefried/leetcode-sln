class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto &pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<bool> marked(numCourses, false);
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
            if (!marked[i]) {
                if (dfs(i,visited,marked,graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(int p, unordered_set<int>& visited, vector<bool> &marked, unordered_map<int, unordered_set<int>> &graph) {
        marked[p] = true;
        if (visited.find(p) != visited.end()) return true;
        visited.insert(p);    
        for (auto &e : graph[p]) {
            if (dfs(e,visited,marked,graph)) return true;
        }
        visited.erase(p);
        return false;
    }
};