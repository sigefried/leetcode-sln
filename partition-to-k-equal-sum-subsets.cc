class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n : nums) {
            sum += n;
        }
        if(sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, 0, k, 0,  sum / k);
    }
    
    bool dfs(vector<int>& nums, vector<bool>& visited, int start_index, int k, int cur_sum, int target){
        
        if(k == 1) return true;
        if(cur_sum == target) {
            return dfs(nums, visited, 0, k-1, 0, target);
        }
        
        for(int i = start_index; i < nums.size(); ++i) {
            if(!visited[i]) {
                visited[i] = true;
                if(dfs(nums,visited, i + 1, k, cur_sum + nums[i], target)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;
    }
};