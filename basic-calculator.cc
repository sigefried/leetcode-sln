class Solution {
public:
    int calculate(string s) {
        stack<long long> rst;
        stack<char> ops;
        long long cur = 0;
        long long ret = 0;
        int sign = 1;
        for(auto ch : s) {
            if(ch == ' ') {
                continue;
            } else if(isdigit(ch)) {
                cur = cur * 10 + (ch - '0');
            } else {
                if (ch == '(') {
                    rst.push(ret);
                    ops.push(sign);
                    ret = 0;
                    sign = 1;
                } else if(ch == ')') {
                    ret = ret + sign * cur;
                    long long old = rst.top(); rst.pop();
                    sign = ops.top(); ops.pop();
                    ret = old + sign * ret;
                    cur = 0;
                    sign = 1;
                } else {
                    ret = ret + sign * cur;
                    cur = 0;
                    sign = ch == '+' ? 1 : -1;  
                }

            }
        }
        cout << ret << " " << sign << " " << cur <<endl;
        if(cur != 0) {
            ret += cur * sign;
        }
        return ret;
    }
};