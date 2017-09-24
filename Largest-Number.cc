class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        for (auto n : nums) {
            tmp.push_back(to_string(n));
        }
        sort(tmp.begin(), tmp.end(), [](string &a, string &b) {
            return a+b > b+a;
        });
        string ret;
        for (auto s : tmp) {
            ret += s;
        }
        int i;
        for (i = 0; i < ret.size() - 1 && ret[i] == '0'; ++i);
        return ret.substr(i);
        
    }
};