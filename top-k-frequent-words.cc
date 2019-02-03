class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(auto w : words) {
            cnt[w]++;
        }
        auto cmp = [](pair<int,string> a, pair<int,string> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp) > pq(cmp);
        for(auto it : cnt) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};