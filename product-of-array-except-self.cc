class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lp (n, 1);
        vector<int> rp (n, 1);
        for (int i = 1; i < n; ++i) {
            lp[i] = lp[i-1] * nums[i-1];
            rp[i] = rp[i-1] * nums[n-i];
        }
        
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = lp[i] * rp[n-i-1];
        }
        return ret;
    }
};