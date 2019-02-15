class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        return {search_left(nums, target), search_right(nums,target)};
    }
    
    int search_left(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        if(nums[l] == target) {
            return l;
        } else if(nums[r] == target) {
            return r;
        } else {
            return -1;
        }
    }

    int search_right(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(nums[m] > target) {
                r = m;
            } else {
                l = m;
            }
        }
        if(nums[r] == target) {
            return r;
        } else if(nums[l] == target) {
            return l;
        } else {
            return -1;
        }
    }
};