class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), (k - 1) / 2);
        vector<double> ret;
        for(int i = k; ;++i) {
            ret.push_back((static_cast<double>(*mid) + *next(mid, (k+1) % 2)) / 2.0);
            
            if(i == nums.size()) return ret;
            
            window.insert(nums[i]);
            if (nums[i] < *mid) mid = prev(mid); 
            if (nums[i - k] <= *mid) mid = next(mid);
            window.erase(window.lower_bound(nums[i - k])); 
        }
    }
};