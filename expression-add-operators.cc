class Solution {
public:
    typedef long long ll;
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        if(num.size() == 0) return ret;
        dfs(ret, num, target, 0, "", 0, "", 0);
        return ret;
    }
    
    void dfs(vector<string> &ret, string &num, int target, int pos, string tmp, ll accu,
            string op, ll pv) {
        if(pos == num.size()) {
            if(accu == target) {
                ret.push_back(tmp);
            }
            return;
        }
        
        for(int end = pos + 1; end <= num.size(); ++end) {
            if(num[pos] == '0' && end != pos + 1) break;
            string raw = num.substr(pos, end - pos);
            ll cur = stol(raw);
            if(tmp == "") {
                dfs(ret, num, target, end, tmp + raw, accu + cur, "", 0);
            } else {
                dfs(ret, num, target, end, tmp + "+" + raw, accu + cur, "+", cur);
                dfs(ret, num, target, end, tmp + "-" + raw, accu - cur, "-", cur);
                if(op == "+") {
                    dfs(ret, num, target, end, tmp + "*" + raw, accu - pv + (pv * cur), "+", pv * cur);
                } else if(op == "-") {
                    dfs(ret, num, target, end, tmp + "*" + raw, accu + pv - (pv * cur), "-", pv * cur);
                } else {
                    dfs(ret, num, target, end, tmp + "*" + raw, accu * cur, "*", cur);
                }
            }
        }
    }
};