class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        ret.push_back(vector<int>());
        int cur_size = 1;
        if (nums.size() == 0) return ret;
        for (int i = 0; i < nums.size(); ++i) {
            int start = (i > 0 && nums[i] == nums[i-1]) ? cur_size : 0;
            cur_size = ret.size();
            for (int j = start; j < cur_size; ++j) {
                vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};