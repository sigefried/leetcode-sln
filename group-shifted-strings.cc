class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> group;
        for(auto s : strings) {
            string key = calc_key(s);
            group[key].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto it : group) {
            ret.push_back(it.second);
        }
        
        return ret;
    }
    
    string calc_key(string s) {
        string key('.',s.size());
        int diff = s[0] - 'a';
        for(int i = 0; i < s.size(); ++i) {
            char shift = s[i] - diff;
            if(shift < 'a') shift += 26;
            key.push_back(shift);
        }
        return key;
    }
};
