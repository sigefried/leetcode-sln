class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_max = -1;
        int ret = 0;
        for(int i = 0; i < arr.size(); ++i) {
            cur_max = max(cur_max, arr[i]);
            if(cur_max == i) ret++;
        }
        return ret;
    }
};