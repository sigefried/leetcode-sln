class Solution {
public:
    string minWindow(string S, string T) {
        int sidx = 0, tidx = 0, slen = S.size(), tlen = T.size();
        int start = -1, len = slen;
        while(sidx < slen) {
            if(S[sidx] == T[tidx]) {
                if(++tidx == tlen) {
                    int end = sidx + 1;
                    while(--tidx >= 0) {
                        while(S[sidx--] != T[tidx]) ;
                    }
                    sidx++;
                    tidx++;
                    if(end - sidx < len) {
                        len = end - sidx;
                        start = sidx;
                    }
                }
            }
            sidx++;
        }
        
        return start == -1 ? "" : S.substr(start, len);
    }
};