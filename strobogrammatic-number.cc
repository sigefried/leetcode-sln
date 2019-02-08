class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> m = {
            {'6', '9'},
            {'9', '6'},
            {'0', '0'},
            {'1', '1'},
            {'8', '8'},
        };
        
        int l = 0, r = num.size() - 1;
        while (l <= r) {
            if (!m.count(num[l])) return false;
            if (m[num[l]] != num[r])
                return false;
            l++;
            r--;
        }
    
        return true;
    }
};