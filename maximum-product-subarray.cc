class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxpre = nums[0];
        int minpre = nums[0];
        int ret = nums[0];
        int maxh, minh;
        for(int i = 1; i < nums.size(); ++i) {
            maxh = max({nums[i], maxpre * nums[i], minpre * nums[i]});
            minh = min({nums[i], maxpre * nums[i], minpre * nums[i]});
            ret = max(maxh, ret);
            maxpre = maxh;
            minpre = minh;
        }
        return ret;
    }
};