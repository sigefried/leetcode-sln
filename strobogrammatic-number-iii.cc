class Solution {
public:
    vector<string> candidates;
    int lsize, rsize;
    int strobogrammaticInRange(string low, string high) {
        int n = high.size();
        lsize = low.size();
        rsize = high.size();
        r_gen(n,n);
        r_gen(n-1,n-1);
        int cnt = 0;
        long long ln = stol(low);
        long long hn = stol(high);
        
        for(auto s : candidates) {
            if(s.size() == 1 || s[0] != '0') {
                long long sn = stol(s);
                if(ln <= sn && sn <= hn) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    vector<string> r_gen(int i, int n) {
        if(i == 0) {
            return {""};
        } else if(i == 1) {
            vector<string> ret = {"1","0","8"};
            if(ret.size() >= lsize) {
                candidates.insert(candidates.end(), ret.begin(), ret.end());
            }
            return ret;
        }
        
        vector<string> sub = r_gen(i-2, n);
        vector<string> ret;
        for(auto s : sub) {
            if(i != n) {
                ret.emplace_back("0" + s + "0");
            }
            ret.emplace_back("8" + s + "8");
            ret.emplace_back("1" + s + "1");
            ret.emplace_back("6" + s + "9");
            ret.emplace_back("9" + s + "6");
        }
        if(ret.size() >= lsize) {
            candidates.insert(candidates.end(), ret.begin(), ret.end());
        }
        return ret;
    }    
};