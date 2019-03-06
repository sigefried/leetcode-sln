class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> cnt;
        int bar = -1;
        int ret = 0;
        int k = 2;
        int d = 0;
        for(int i = 0; i < tree.size(); ++i) {
            if(cnt[tree[i]]++ == 0) d++;
            while(d > 2) {
                if(--cnt[tree[++bar]] == 0) d--;
            }
            ret = max(ret, i - bar);
        }
        return ret;
    }
};