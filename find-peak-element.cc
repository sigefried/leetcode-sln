class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (nums[m] < nums[m+1]) {
                l = m;
            } else {
                r = m;
            }
        }
        if (nums[l] > nums[r]) {
            return l;
        } else {
            return r;
        }
    }
};