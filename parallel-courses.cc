class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        map<int, set<int>> mp;
        vector<int> indegree(N + 1, 0);
        for(auto it : relations) {
            mp[it[0]].insert(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= N; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while(!q.empty()) {
            for(int sz = q.size(); sz > 0; --sz)  {
                --N;
                int cur = q.front(); q.pop();
                if(mp.count(cur)==0) continue;
                for(auto n : mp[cur]) {
                    if(--indegree[n] == 0) {
                        q.push(n);
                    }
                }
            }
            cnt++;
        }
        
        return N == 0 ? cnt : -1;
    }
};