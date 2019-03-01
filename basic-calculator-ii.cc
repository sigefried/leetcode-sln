class Solution {
public:
    bool is_ops(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    
    int prec(char c) {
        if (c == '+' || c == '-') {
            return 1;
        } else if (c == '*' || c == '/') {
            return 2;
        }
        return 0;
    }
    
    void calc(stack<char> &ops, stack<int> &num) {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char op = ops.top(); ops.pop();
        int rst = eval(op, a, b);
        num.push(rst);
    }
    
    int eval(char op, int a, int b) {
       
        if(op == '+') {
            return a + b;
        } else if(op == '-') {
            return a - b;
        } else if(op == '*') {
            return a * b;
        } else {
            // /
            return a / b;
        }
    }
    
    int calculate(string s) {
        stack<char> ops;
        stack<int> num;
        int cur = 0;
        for(int i = 0; i < s.size();) {
            if(s[i] == ' ') {
                ++i;
                continue;
            }
            if(isdigit(s[i])) {
                cur = 0;
                while(i < s.size() && isdigit(s[i])) {
                    cur = 10 * cur + (s[i] - '0');
                    i++;
                }
                num.push(cur);
            } else {
                // is operator
                while(!ops.empty() && prec(s[i]) <= prec(ops.top()) ) {
                    calc(ops, num);
                }
                ops.push(s[i]);
                ++i;
            }
        }
        while(!ops.empty()) {
            calc(ops,num);
        }
        return num.top();
    }
};