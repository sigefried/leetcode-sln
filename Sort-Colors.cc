class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int begin = -1;
        int end = nums.size();
        for (int i = 0; i < nums.size();) {
            if (nums[i] == 0 && i > begin) {
                swap(nums[++begin], nums[i]);
            } else if (nums[i] == 2 && i < end) {
                swap(nums[--end], nums[i]);
            } else {
                i++;
            }
        }
    }
};