class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
       string ret = "";
        for(auto cand : d) {
            if (cand.size() >= ret.size() && isSub(cand, s)) {
                if (cand.size() > ret.size() || (cand.length() == ret.size() && cand < ret) )
                    ret = cand;
            }
        }
        return ret;
    }
    
    bool isSub(string sub_x, string x) {
        int j = 0;
        for(int i = 0; i < x.size() && j < sub_x.size(); ++i) {
            if(x[i] == sub_x[j]) {
                j++;
            }
        }
        return j == sub_x.size();
    }
};