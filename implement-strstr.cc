class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        auto lps = pre_process(needle);
        //for(auto n : lps) cout << n << " ";
        for(int i = 0, j = 0; i < m;) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = lps[j-1];
            }
            if(needle[j] == haystack[i]) {
                ++j;
                ++i;
            } else {
                ++i;
            }

            if(j == n) {
                return i - j;
            }
        }
        return -1;
    }
    
    vector<int> pre_process(string needle) {
        int n = needle.size();
        vector<int> lps(n,0);
        for(int i = 1, len = 0; i < n; ++i) {
            while(len > 0 && needle[len] != needle[i]) {
                len = lps[len-1];
            }
            if(needle[len] == needle[i]) {
                len++;
            }
            lps[i] = len;
        }
        return lps;
    }
};