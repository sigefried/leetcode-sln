class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return r_gen(n, n);
    }
    
    vector<string> r_gen(int i, int n) {
        if(i == 0) {
            return {""};
        } else if(i == 1) {
            return {"1","0","8"};
        }
        
        vector<string> sub = r_gen(i-2, n);
        vector<string> ret;
        for(auto s : sub) {
            if(i != n) {
                ret.emplace_back("0" + s + "0");
            }
            ret.emplace_back("8" + s + "8");
            ret.emplace_back("1" + s + "1");
            ret.emplace_back("6" + s + "9");
            ret.emplace_back("9" + s + "6");
        }
        return ret;
    }
};