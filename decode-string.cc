class Solution {
public:
    string decodeString(string s) {
        stack<int> repeatStk;
        stack<string> rStringStk;
        string res = "";
        int repeat = -1;
        rStringStk.push("");
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                repeatStk.push(count);
            } else if (s[i] == '[') {
                rStringStk.push(res);
                res = "";
                i++;
            } else if (s[i] == ']') {
                string oldRes = rStringStk.top();
                rStringStk.pop();
                int rt = repeatStk.top();
                repeatStk.pop();
                while (rt--) {
                    oldRes += res;
                }
                res = oldRes;
                i++;
            } else {
                res.push_back(s[i++]);
            }
        }
        return res;
    }
};