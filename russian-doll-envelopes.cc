class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() <= 1) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b){
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        int N = envelopes.size();
        if(N == 0) return 0;
        vector<pair<int, int>> end(N, {0,0});
        int sz = 0;
        for (int i = 0; i < N; i++) {
            int l = 0, r = sz;
            while(l < r) {
                int m = (l + r) / 2;
                if (envelopes[i].first > end[m].first && envelopes[i].second > end[m].second) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
           // cout << l << "," << envelopes[l].first << "," << envelopes[l].second << endl;
            //for(auto it : end) {
            //   cout << it.first << "," << it.second << endl;
           // }
            //cout << "---------" << endl;
            end[l] = envelopes[i];
            if(l == sz) sz++;
            
        }

        return sz;
        
    }
};