class Solution {
public:
    vector<int> count, sum;
    unordered_map<int, unordered_set<int>> graph;
    int total;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        sum = vector<int>(N, 0);
        total = N;
        count = sum;
        for(auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        unordered_set<int> vs1, vs2;
        dfs1(0, vs1);
        dfs2(0, vs2);
        return sum;
    }
    
    void dfs1(int cur, unordered_set<int> &visited) {
        visited.insert(cur);
        for(auto i : graph[cur]) {
            if(visited.count(i)) continue;
            dfs1(i, visited);
            count[cur] += count[i];
            sum[cur] += sum[i] + count[i];
        }
        count[cur] += 1;
    }
    void dfs2(int cur, unordered_set<int> &visited) {
        visited.insert(cur);
        for(auto i : graph[cur]) {
            if(visited.count(i)) continue;
            sum[i] = sum[cur] - count[i] + total - count[i];
            dfs2(i, visited);
        }
    }
    
};