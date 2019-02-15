class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> m;
        int n = speed.size();
        for(int i = 0; i < n; ++i) {
            m[-position[i]] = (double)(target - position[i])  / speed[i];
        }
        
        int ret = 0;
        double cur = 0;
        for(auto it : m) {
            if(it.second > cur) {
                cur = it.second;
                ret++;
            }
        }
        return ret;
        
    }
};