class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> oprands;
        for(auto t : tokens) {
            if(isdigit(t[0]) || t.size() > 1) {
                oprands.push(stoi(t));
            } else {
                int a = oprands.top(); oprands.pop();
                int b = oprands.top(); oprands.pop();
                int rs = eval(t, b, a);
                oprands.push(rs);
            }
           
        }
        return oprands.top();
    }
    
    int eval(string ops, int a, int b) {
        if(ops == "+") {
            return a + b;
        } else if (ops == "-") {
            return a - b;
        } else if (ops == "*") {
            return a * b;
        } else if (ops == "/") {
            return a / b;
        }
                
                
        
        return -1;
    }
};