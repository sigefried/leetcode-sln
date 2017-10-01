class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> corner;
        for (auto &build : buildings) {
            corner.push_back({build[0], -build[2]});
            corner.push_back({build[1], build[2]});
        }
        sort(corner.begin(), corner.end(), [](pair<int,int> &a, pair<int,int> &b){
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        
        vector<pair<int,int>> ret;
        unordered_map<int,int> deleted;
        priority_queue<int> pq;
        pq.push(0);
        int prev = 0;
        for (auto &c : corner) {
            if (c.second < 0) {
                pq.push(-c.second);
            } else {
                deleted[c.second]++;    
                while (!pq.empty() && deleted[pq.top()] >0 ){
                    deleted[pq.top()] -= 1;
                    pq.pop();
                }
            }
            int cur = pq.top();
            if (cur != prev) {
                ret.push_back({c.first, cur});
                prev = cur;
            }
            
        }
        return ret;
    }
};