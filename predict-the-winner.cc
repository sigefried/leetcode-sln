class Solution {
public:
    unordered_map<int, unordered_map<int,int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size() - 1;
        int sum = 0;
        for(auto n : nums) {
            sum += n;
        }
        int tmp = getMax(nums, 0 , n);
        return tmp >= (sum - tmp); 
    }
    int getMax(vector<int> &nums, int i, int j) {
        if(memo[i][j] > 0) {
            return memo[i][j];
        }
        if(i == j) {
            return nums[i];
        } else if(i + 1 == j) {
            return max(nums[i], nums[j]);
        }
        
        int ret = max(nums[i] + min(getMax(nums,i+1, j-1), getMax(nums,i+2,j)),
                  nums[j] + min(getMax(nums,i,j-2), getMax(nums,i+1,j-1)));
        memo[i][j] = ret;
        return ret;
    }
};