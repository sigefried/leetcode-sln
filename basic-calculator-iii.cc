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
    
    void calc(stack<char> &ops, stack<long long> &num) {
        long long b = num.top(); num.pop();
        long long a = num.top(); num.pop();
        char op = ops.top(); ops.pop();
        long long rst = eval(op, a, b);
        num.push(rst);
    }
    
    long long eval(char op, long long a, long long b) {
       
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
        stack<long long> num;
        long long cur = 0;
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
            } else if(s[i] == '(') {
                ops.push(s[i]);
                i++;
            } else if(s[i] == ')') {
                while(!ops.empty() && ops.top() != '(' ) {
                    calc(ops, num);
                }                
                ops.pop(); // pop (
                i++;
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