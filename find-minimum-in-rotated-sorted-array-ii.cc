class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] > nums[r]) {
                l = m + 1;
            } else if(nums[m] < nums[l]) {
                r = m;
            } else {
                r-= 1;
            }
        }
        return nums[l];
    }
};