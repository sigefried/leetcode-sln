class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ret = 1;
        for(int i = 1; i < n; ++i) {
            int maxval = 0;
            for(int j = 0; j< i; ++j) {
                if(nums[i] > nums[j]) {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// tails dp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int sz = 0;
        vector<int> tails(n, 0);
        for(auto n : nums) {
            int l = 0, r = sz;
            while(l < r) {
                int m = (l + r) / 2;
                if(tails[m] < n) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            
            tails[l] = n;
            if(l == sz) ++sz;
        }
        
        return sz;
    }
};