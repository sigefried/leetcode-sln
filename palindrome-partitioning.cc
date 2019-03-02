class Solution {
public:
    vector<vector<string>> ret;
    int n = 0;
    map<string, bool> memo;
    vector<vector<string>> partition(string s) {
        n = s.size();
        if(n == 0) return ret;
        vector<string> tmp;
        dfs(0, s, tmp);
        return ret;
    }
    
    void dfs(int cur, string &s, vector<string> &tmp) {
        if(cur == n) {
            ret.push_back(tmp);
            return;
        }
        
        for(int end = cur + 1; end <= s.size(); ++end) {
            string sub = s.substr(cur, end - cur);
            if(isPal(sub)) {
                tmp.push_back(sub);
                dfs(end, s, tmp);
                tmp.pop_back();
            }
        }
    }
    
    bool isPal(string s) {
        if(memo.count(s) > 0) return memo[s];
        int ret = true;
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                ret = false;
                break;
            }
            l++;
            r--;
        }
        
        memo[s] = ret;
        return ret;
    }
};