class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> idx(26);
        for(int i = 0; i < S.size(); ++i) {
            idx[S[i] - 'a'].push_back(i);
        }
        int ret = 0;
        for(auto &word : words) {
            bool found = true;
            int pt = -1;
            
            for(char ch : word) {
                auto it = upper_bound(idx[ch - 'a'].begin(),idx[ch - 'a'].end(), pt);
                if(it == idx[ch - 'a'].end()) {
                    found = false;
                    break;
                } else {
                    pt = *it;
                }
            }
            if(found ) ret++;
        }
        return ret;
    }
};