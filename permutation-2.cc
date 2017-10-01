class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        r_gen(ret, nums, tmp, 0, visited);
        return ret;
    }
    
     void r_gen(vector<vector<int>> &ret, vector<int> &nums, vector<int> &tmp, int count, vector<bool> &visited) {
        if (nums.size() == count) {
            ret.push_back(tmp);
            return;
        }
            
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                tmp.push_back(nums[i]);
                r_gen(ret, nums, tmp, count+1, visited);
                tmp.pop_back();
                visited[i] = false;
            }

        }
        return;
    }
};