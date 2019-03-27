class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int a = convert(S);
        int b = convert(T);
        if(a != b) return false;
        for(int i = 0; i < a; ++i) {
            if(S[i] != T[i]) return false;
        }
        return true;
    }
    int convert(string &s) {
        int bar = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '#') {
                s[bar++] = s[i];
            } else {
                if(bar > 0) {
                    bar--;
                }
            }
        }
        
        return bar;
    }
};