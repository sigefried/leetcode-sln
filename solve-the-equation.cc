class Solution {
public:
    string solveEquation(string equation) {
        int index = equation.find('=');
        vector<int> left = getRes(equation.substr(0, index));
        vector<int> right = getRes(equation.substr(index + 1));

        int x = left[0] - right[0];
        int num = right[1] - left[1];
        string res = "";
        if (x == 0 && num == 0)
            res = "Infinite solutions";
        else if (x == 0 && num != 0)
            res = "No solution";
        else
            res = "x=" + to_string(num / x);

        return res;
    }
    // {xcoeff, sum}
    vector<int> getRes(string s) {
        int sign = 1;
        int sum = 0;
        int cur = 0;
        int xcoeff = 0;
        //cout << s << endl;
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                cur = cur * 10 + (s[i] - '0');
            } else {
                if(s[i] == 'x') {
                    if(i > 0 && isdigit(s[i-1])) {
                        xcoeff += sign *  cur;
                    } else {
                        xcoeff += sign;
                    }
                } else {
                    if(s[i-1] != 'x') {
                        sum += sign * cur;
                    }
                    sign = s[i] == '+' ? 1 : -1;
                }
                cur = 0;
            }
        }
        if(cur != 0 && s.back() != 'x') {
            sum += sign* cur;
        }
        //cout << "sum:" << sum << " xcoeff: " << xcoeff << endl;
        return {xcoeff, sum};
    }
}; 