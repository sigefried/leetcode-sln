class Solution {
public:
    
    vector<vector<int>> children;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        children.resize(n);
        for(int i = 0; i < manager.size(); ++i) {
            if(manager[i] != -1) {
                children[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }
    
    int dfs(int cur, vector<int> &informTime) {
        int time = 0;
        for(auto &n : children[cur]) {
            time = max(time, dfs(n, informTime));
        }
        return informTime[cur] + time;
    }
};