class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ret = INT_MAX;
        int bar = -1;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            while(sum >= s) {
                ret = min(ret, i - bar);
                sum -= nums[++bar];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};