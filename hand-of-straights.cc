class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cnt;
        for(auto n : hand) cnt[n]++;
        for(auto it : cnt) {
            if(cnt[it.first] > 0) {
                int delta = cnt[it.first];
                for(int i = 0; i < W; ++i) {
                    if(cnt.count(it.first + i) > 0 && cnt[it.first + i] >= cnt[it.first]) {
                        
                        cnt[it.first + i] -= delta;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};