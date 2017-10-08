class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        vector<int> indegree(numCourses, 0);
        for (auto &pre : prerequisites) {
            graph[pre.second].insert(pre.first);
            indegree[pre.first]++;
        }
        vector<int> ret;
        toposort(ret, graph, indegree, numCourses);
        return ret;
    }
    
    void toposort(vector<int> &ret, unordered_map<int, unordered_set<int>>& graph, vector<int> &indegree, int numCourses) {
        vector<bool> visited(numCourses, false);
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int target = q.front();
            q.pop();
            count++;
            visited[target] = true;
            ret.push_back(target);
            for (auto e : graph[target]) {
                if (!visited[e]) {
                    indegree[e]--;
                    if (indegree[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }
        if (count != numCourses) {
            ret.clear();
        }
    }
};