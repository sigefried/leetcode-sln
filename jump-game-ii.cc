class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int curFar = 0;
        int nextFar = 0;
        for(int i = 0; i < nums.size(); ++i) {
            nextFar = max(nextFar, i + nums[i]);
            if(i == nums.size() - 1) {
                return ret;
            }
            if(i == curFar) {
                ret++;
                curFar = nextFar;
            }
        }
        return 0;
    }
};