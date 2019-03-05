class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double,int>> ranked;
        for(int i = 0; i < n; ++i) {
            ranked.push_back({wage[i] * 1.0 / quality[i], quality[i]});
        }
        sort(ranked.begin(),ranked.end(), [](auto a, auto b) { return a.first < b.first; });
        
        priority_queue<int> pq;
        int total = 0;
        double ret = INT_MAX;
        for(auto p : ranked) {
          //  cout << p.first << " " << p.second << endl;
            if(pq.size() < K - 1) {
                total += p.second;
                pq.push(p.second);
            } else {
                double ratio = p.first;
                pq.push(p.second);
                total += p.second;
                if(pq.size() > K) {
                    total -= pq.top(); pq.pop();
                }
               // cout << ratio << "-" << total << endl;
                ret = min(ret, ratio * total);
            }
        }
        return ret;
    }
};