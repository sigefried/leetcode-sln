class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto n : nums) {
            if(n <= min1) {
                min1 = n;
            } else if(n <= min2) {
                min2 = n;
            } else {
                return true;
            }
        }
        return false;
    }
};