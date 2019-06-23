class Solution {
public:
    vector<int> nums = {0,1,6,8,9};
    int ret = 0;
    int N;
    map<int, int> rMap = {
        {0,0},
        {1,1},
        {8,8},
        {6,9},
        {9,6}
    };
    int confusingNumberII(int N) {
        this->N = N;
        dfs(0);
        return ret;
    }
    
    void dfs(long long cur) {
        if(cur > N) return;
        if(cur <= N && check(cur)) {
            ret++;
        }
        
        int start = (cur == 0 ? 1 : 0);
        for(int i = start; i < nums.size(); ++i) {
            dfs(cur * 10 + nums[i]);
        }
    }
    
    bool check(long long n) {
        string r = "";
        string sn = to_string(n);
        for(auto ch : sn) {
            int d = ch - '0';
            r = to_string(rMap[d]) + r;
        }
        return r != sn;
    }
};