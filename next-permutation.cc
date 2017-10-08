class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        for (; i >= 0 && nums[i+1] <= nums[i];--i);
        if (i >= 0) {
            int j = nums.size() - 1;
            for (;j >= 0 && nums[j] <= nums[i];j--);
            swap(nums[i],nums[j]);
        }
        
        reverse(nums, i+1);
    }
    
    void reverse(vector<int> &nums, int start) {
        int l = start;
        int r = nums.size() - 1;
        while (l < r) {
            swap(nums[l++],nums[r--]);
        }
    }
};