class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        return max(doRob(nums,0,n-1), doRob(nums,1,n));
    }
    
    int doRob(vector<int> &nums, int start, int end) {
        int pre_max = 0;
        int cur_max = 0;
        for (int i = start; i < end; ++i) {
            int tmp = max(pre_max + nums[i], cur_max);
            pre_max = cur_max;
            cur_max = tmp;
        }
        return cur_max;
    }
};