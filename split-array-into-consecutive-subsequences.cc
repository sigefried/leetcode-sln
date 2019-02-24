class Solution {
public:
    unordered_map<int, int> freq, end;
    bool isPossible(vector<int>& nums) {
        for(auto n : nums) {
            freq[n]++;
        }
        
        for(auto n : nums) {
            if(freq[n] == 0) continue;
            if(end[n-1] > 0) {
                // merge into existing
                freq[n]--;
                end[n-1]--;
                end[n]++;
            } else if(freq[n+1] > 0 && freq[n+2] > 0) {
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                end[n+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};