class Solution {
public:
    int ret = 0;
    typedef long long ll;
    vector<ll> tmp;
    void merge_sort(vector<ll> &nums, int l, int r) {
        if(l >= r - 1) return;
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m, r);
        int rb = m;
        for(int lb = l; lb < m; ++lb) {
            while(rb < r && nums[lb] > 2 * nums[rb]) rb++;
            ret += (rb - m);
        }
        int i = l, j = m;
        for(int k = l; k < r; ++k) {
            if( j == r || ( i < m && nums[i] < nums[j])) {
                tmp[k] = nums[i++];
            } else {
                tmp[k] = nums[j++];
            }
        }
        
        for(int k = l; k < r; ++k) {
            nums[k] = tmp[k];
        }
    }
    int reversePairs(vector<int>& nums) {
        int l = 0, r = nums.size();
        vector<ll> lnum(nums.begin(), nums.end());
        tmp = lnum;

        merge_sort(lnum, l, r);
       // for(auto n : nums) {
       //     cout << n << endl;
       // }
        return ret;
    }
};