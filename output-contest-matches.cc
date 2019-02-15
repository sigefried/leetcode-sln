class Solution {
public:
    string findContestMatch(int n) {
        vector<string> str(n);
        for(int i = 0; i < n; ++i) {
            str[i] = to_string(i + 1);
        }
        for(;n > 1; n /= 2) {
            for(int i = 0; i < n / 2; ++i) {
                str[i] = "(" + str[i] + "," + str[n-1-i] + ")";
            }
        }
        return str[0];
    }
};