class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int,int> cnt;
        for(auto n : A) {
            cnt[n]++;
        }
        sort(A.begin(), A.end(), [](auto a, auto b){ return abs(a) < abs(b); });
        
        for(auto n : A) {
            if(cnt[n] == 0) continue;
            if(cnt[2*n] == 0) return false;
            
            cnt[n]--;
            cnt[2*n]--;
        }
        return true;
    }
};