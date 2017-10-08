class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        int leftCount = 0;
        int rightCount = 0;
        for (auto c : s) {
            if (c == '(') leftCount++;
            if (c == ')') {
                if (leftCount != 0) {
                    --leftCount;
                } else {
                    ++rightCount;
                }
            }
        }
        if (leftCount == 0 && rightCount == 0) {
            ret.push_back(s);
            return ret;
        }
        unordered_set<string> ret_tmp;
        dfs(s,0,leftCount,rightCount,"", 0, ret_tmp);
        return vector<string>(ret_tmp.begin(), ret_tmp.end());
    }
    
    void dfs(string s, int index, int leftCount, int rightCount, string tmp, int pair,  unordered_set<string>& ret) {
        if (index == s.size()) {
            if (leftCount == 0 && rightCount == 0) {
                ret.insert(tmp);
            }
            return;
        }
        
        if (s[index] != '(' && s[index] != ')') {
            dfs(s, index + 1, leftCount, rightCount, tmp + s[index], pair, ret);
        } else {
            if (s[index] == '(') {
                if (leftCount > 0) {
                    dfs(s, index + 1, leftCount - 1, rightCount, tmp, pair, ret);
                }
                dfs(s, index + 1, leftCount, rightCount, tmp + s[index], pair + 1, ret);
            } else if (s[index] == ')') {
                if (rightCount > 0) {
                    dfs(s, index + 1, leftCount, rightCount - 1, tmp, pair, ret);
                }
                if (pair > 0) {
                    dfs(s, index + 1, leftCount, rightCount, tmp + s[index], pair - 1, ret);
                }
            }
        }
        
        
    }
};