class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> rank(26, vector<int>(26, 0));
        
        for(auto &v : votes) {
            for(int i = 0; i < v.size(); ++i) {
                rank[v[i] - 'A'][i]++;
            }
        }
        
        string x = votes[0];
        
        sort(x.begin(), x.end(), [&](char a, char b) {
            if (rank[a - 'A'] == rank[b - 'A']) {
                return a < b;
            }
            return rank[a - 'A'] > rank[b - 'A'];
        });
        
        return x;
    }
};