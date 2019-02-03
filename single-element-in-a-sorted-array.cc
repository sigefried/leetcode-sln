class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if(m % 2 == 1) m--;
            
            if(nums[m] == nums[m+1]) {
                l += 2;
            } else {
                r = m;
            }
        }
        
        return nums[l];

    }
};