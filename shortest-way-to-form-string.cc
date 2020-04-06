class Solution {
public:
    int shortestWay(string source, string target) {
        vector<int> ch_ids[26];
        for(int i = 0; i < source.size(); ++i) {
            ch_ids[source[i] - 'a'].push_back(i);
        }
        int cur = -1;
        int ans = 0;
        for(int i = 0; i < target.size(); ) {
            auto &ids = ch_ids[target[i] - 'a'];
            if(ids.empty()) return -1;
            
            auto it = upper_bound(ids.begin(), ids.end(), cur);
            if(it == ids.end()) {
                ans++;
                cur = -1;
            } else {
                ++i;
                cur = *it;
            }
        }
        
        return ans+1;
        
        
    }
};