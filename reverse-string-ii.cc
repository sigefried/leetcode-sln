class Solution {
public:
    
    void do_it(string &s, int l, int r){
        while(l<r) {
            swap(s[l++],s[r--]);
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2 * k) {
            int e = min(n-1, i + k - 1);
            do_it(s,i,e);
        }
        return s;
    }
};