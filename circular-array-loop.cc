class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int start = 0; start < n; ++start) {
            if(nums[start] == 0) continue;
            int slow = start, fast = getIndex(start, nums);
            while (nums[fast] * nums[start] > 0 && nums[getIndex(fast, nums)] * nums[start] > 0) {
                if (fast == slow) {
                    if (fast == getIndex(fast, nums)) {
                        break;
                    }
                    return true;
                }
                slow = getIndex(slow, nums);
                fast = getIndex(getIndex(fast, nums), nums);
            }

        }
        return false;
    }
    
    int getIndex(int i, vector<int> &nums) {
        int n = nums.size();
        int nxt = i + nums[i];
        return (nxt % n + n ) % n;

    }
};