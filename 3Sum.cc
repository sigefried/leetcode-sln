class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        findThreeSum(ret, nums);
        return ret;
    }
    
    void findThreeSum(vector<vector<int>> &ret, vector<int>& nums) {
        for (int t = 0; t < nums.size() - 2; t++) {
            if (t > 0 && nums[t] == nums[t-1]) continue;
            int target = -nums[t];
            int l = t+1;
            int r = nums.size() - 1;
            while (l < r) {
                int curSum = nums[l] + nums[r];
                if (curSum == target) {
                    vector<int> tmp = {-target ,nums[l], nums[r]};
                    ret.push_back(tmp);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                } else if (curSum > target) {
                    r--;
                } else {
                    l++;
                }
            }   
        }
    }
};