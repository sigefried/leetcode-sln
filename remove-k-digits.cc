class Solution {
public:
    string removeKdigits(string num, int k) {
        int cnt = 0;
        string stk;
        int new_len = num.size() - k;
        for(char ch : num) {      
            while(!stk.empty() && stk.back() > ch && cnt < k) {
                stk.pop_back();
                cnt++;
            }
            stk.push_back(ch);
        }
        if(stk.size() > new_len) {
            stk = stk.substr(0, new_len);
        }
        int start = 0;
        while(start < stk.size() && stk[start] == '0') start++;
        return start == stk.size() ? "0" : stk.substr(start);
    }
};