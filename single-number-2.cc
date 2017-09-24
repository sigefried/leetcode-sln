class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;
        for (auto n : nums) {
            twos |= ones & n;
            ones ^= n;
            threes = ones & twos;
            
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};