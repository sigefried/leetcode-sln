class Solution {
public:
    map<int, int> mp; //sum idx
    vector<vector<int>> arrays;
    int sum;
    Solution(vector<vector<int>> rects) {
        arrays = rects;
        sum = 0;
        for(int i = 0; i < rects.size(); ++i) {
            auto rect = rects[i];
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            mp[sum] = i;
        }
        
    }
    
    vector<int> pick() {
        int idx = mp.lower_bound( rand() % sum + 1)->second;
        return pick_point(arrays[idx]);
    }
    
    vector<int> pick_point(vector<int> rect) {
        int left = rect[0], right = rect[2], bot = rect[1], top = rect[3];
        int width = right - left + 1;
        int height = top - bot + 1;
        return { left + rand() % width, bot + rand() % height};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */