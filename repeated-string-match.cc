class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int ret = 1;
        string s = A;
        for(;s.size() < B.size(); s += A, ret++);
        if(s.find(B) != string::npos) return ret;
        s += A;
        ret++;
        if(s.find(B) != string::npos) return ret;
        return -1;
    }
};
