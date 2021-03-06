class Solution {
public:
    int rob(vector<int>& nums) {
        int preMax = 0;
        int curMax = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int temp = curMax;
            curMax = max(preMax + nums[i], temp);
            preMax = temp;
        }
        
        return curMax;
    }
};