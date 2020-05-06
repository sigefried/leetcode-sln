class Solution {
public:
    vector<bool> visited;
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> idxOfVal;
        for(int i = 0; i < arr.size(); ++i) {
            idxOfVal[arr[i]].push_back(i);
        }
        
        visited = vector<bool>(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int step = 0;
        while(!q.empty()) {
            for(int sz = q.size(); sz > 0; --sz) {
                int cur = q.front(); q.pop();
                if(cur == n-1) return step;
                vector<int> &nxt = idxOfVal[arr[cur]];
                if(valid(cur-1,n)) {
                    q.push(cur-1);
                    visited[cur-1] = true;
                };
                if(valid(cur+1,n)) {
                    q.push(cur+1);
                    visited[cur+1] = true;
                }
                for(int x : nxt) {
                    if(valid(x, n)) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
                nxt.clear();
            }
            step++;
        }
        
        return 0;
    }
    bool valid(int i, int n) {
        return i>=0 && i < n && !visited[i];
    }
};