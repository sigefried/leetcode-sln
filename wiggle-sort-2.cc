class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end(), [](int a, int b) { return a > b; });
        int mid = nums.size() / 2;
        int even = 0;
        int odd = mid;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = sorted[i&1 ? even++ : odd++];
        }
    }
};