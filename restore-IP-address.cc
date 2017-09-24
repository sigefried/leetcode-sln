class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> tmp;
        dfs(ret,s,tmp,0);
        return ret;
    }
    void dfs(vector<string> &ret, string &s, vector<string> &tmp, int start) {
        if (tmp.size() > 4) return;
        if (start == s.size() && tmp.size() == 4) {
            string ip = "";
            for (auto &t : tmp) {
                ip += t;
                ip += ".";
            }
            ip = ip.substr(0, ip.size() - 1);
            ret.push_back(ip);
            return;
        }
        for (int end = start; end < s.size() && end < start+3; ++end) {
            int len = end-start+1;
            string cur = s.substr(start, len);
            if (isValidIP(cur)) {
                tmp.push_back(cur);
                dfs(ret, s, tmp, end+1);
                tmp.pop_back();
            }
        }
    }
    
    bool isValidIP(string &s) {
        if (s.size() > 3 || s.size() == 0 || (s[0] == '0' && s.size() > 1)) return false;
        int n = stoi(s);
        return n >= 0 && n <=255;
    }
};