class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(do_rob(nums, 0, n-2), do_rob(nums,1,n-1));
    }
    
    int do_rob(vector<int>& nums, int start, int end) {
        int preMax = 0;
        int curMax = 0;
        for(int i = start; i <= end; ++i) {
            int temp = curMax;
            curMax = max(preMax + nums[i], temp);
            preMax = temp;
        }
        
        return curMax;
    }
};