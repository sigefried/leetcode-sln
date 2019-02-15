class Solution {
public:
    vector<string> ret;
    int sz;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> m;
        sz = tickets.size();
        for(auto it : tickets) {
            m[it.first].insert(it.second);
        }

        dfs("JFK", m);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    void dfs(string cur,  map<string, multiset<string>> &m ) {

        while(m[cur].size() > 0) {
            string nxt = *m[cur].begin();
            m[cur].erase(m[cur].begin());
            dfs(nxt, m);
        }
        ret.push_back(cur);
    }
};