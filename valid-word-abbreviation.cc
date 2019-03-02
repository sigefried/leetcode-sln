class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size();
        int i = 0, j = 0;
        int cnt = 0;
        while(i < m && j < n) {
            if(word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            } 
            if(abbr[j] <= '0' || abbr[j] > '9') {
                return false;
            }
            int cnt = 0;
            while(j < n && isdigit(abbr[j])) {
                cnt = cnt * 10 + (abbr[j] - '0');
                j++;
            }
            i += cnt;
        }
        return i == m && j == n;
    }
};