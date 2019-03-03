class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret, event(length + 1 , 0);
        for(int i = 0; i < updates.size(); ++i) {
            event[updates[i][0]] += updates[i][2];
            event[updates[i][1] + 1] -= updates[i][2]; 
        }
        int sum = 0;
        for(int i = 0; i < length; ++i) {
            sum += event[i];
            ret.push_back(sum);
        }
        return ret;
    }
};