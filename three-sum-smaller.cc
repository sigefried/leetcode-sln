class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        for(int k = 0; k < nums.size() - 2; ++k) {
            int l = k + 1, r = nums.size() - 1;
            
            while(l < r) {
                int sum = nums[k] + nums[l] + nums[r];
                if(sum < target) {
                    ret += (r - l);
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ret;
    }
};
