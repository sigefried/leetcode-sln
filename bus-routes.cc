class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> take;
        for(int i = 0; i < routes.size(); ++i) {
            for(auto stop : routes[i]) {
                take[stop].insert(i);
            }
        }
        unordered_set<int> visited;
        
        queue<pair<int,int>> q;
        q.push({S, 0});
        visited.insert(S);
        while(!q.empty()) {
            int stop = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(stop == T) return cnt;
            
            for(auto bus : take[stop]) {
                for(auto next_stop : routes[bus]) {
                    if(visited.count(next_stop) == 0) {
                        visited.insert(next_stop);
                        q.push({next_stop, cnt + 1});
                    }
                }
            }
            
        }
        
        return -1;
    }
};