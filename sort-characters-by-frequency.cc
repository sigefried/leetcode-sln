class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> count;
        for (auto c : s) {
            count[c]++;
        }
        
        vector<string> bucket(s.size() + 1, "");
        for (auto &it : count) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n,c);
        }
        string ret = "";
        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty()) {
                ret += bucket[i];
            }
        }
        return ret;
    }
};