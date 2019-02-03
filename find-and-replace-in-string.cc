class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>> idx(indexes.size());
        for(int i = 0; i < indexes.size(); ++i) {
            idx[i] = {indexes[i], i};
        }
        sort(idx.rbegin(),idx.rend());
        for(auto it : idx) {
            int p = it.first;
            string s = sources[it.second];
            string t = targets[it.second];
            if(S.substr(p, s.size()) == s) {
                S = S.substr(0,p) + t + S.substr(p+s.size());
            }
        }
        return S;
    }
};