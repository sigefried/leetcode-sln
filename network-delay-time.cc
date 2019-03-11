class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int n = N;
        vector<int> d(n + 1, INT_MAX / 2);
        
        map<int,map<int,int>> graph;
        
        for(int i=0; i < times.size(); i++){
            int u = times[i][0], v = times[i][1], c = times[i][2];
            graph[u][v] = c;
        }        
        queue<int> q;
        set<int> inqueue;
        d[K] = 0;
        inqueue.insert(K);
        q.push(K);
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            inqueue.erase(cur);
           // cout << cur << endl;
            for(auto it : graph[cur]) {
                int e = it.first;
                int c = it.second;
                //cout << "e:" << e << endl;
                if(d[e] > d[cur] + c) {
                    d[e] = d[cur] + c;
                    if(inqueue.count(e) == 0) {
                        inqueue.insert(e);
                        q.push(e);
                    }
                }
            }
        }
        
        int ret = 0;
        for(int i = 1; i <d.size(); ++i) {
            ret = max(d[i], ret);
        }
        return ret == INT_MAX / 2 ? -1 : ret;
    }
};