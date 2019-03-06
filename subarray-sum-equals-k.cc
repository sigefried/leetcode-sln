class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        if(nums.size() == 0) return 0;

        int ret = 0;
        int sum = 0;
        cnt[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(cnt.count(sum - k)) {
                ret += cnt[sum-k];
                
            }
            cnt[sum] += 1;
        }
        return ret;
    }
};