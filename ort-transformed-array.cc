class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ret(n,0);
        int i = 0, j = n - 1;
        int p = a >= 0 ? j : i;
        while(i <= j) {
            if(a >= 0) {
                ret[p--] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            } else {
                ret[p++] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
            }
        }
        return ret;
    }
    
    int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};