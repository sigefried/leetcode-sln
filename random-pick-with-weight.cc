class Solution {
public:
    vector<int> sum;
    Solution(vector<int> w) {
        sum = w;
        for(int i = 1; i < sum.size(); ++i) {
            sum[i] += sum[i-1];
        }
    }
    
    int pickIndex() {
        int max = sum.back();
        int target = rand() % max + 1;
        int l = 0, r = sum.size() - 1;
        while(l + 1 < r) {
            int m  = (l + r) >> 1;
            
            if(sum[m] == target) {
                return m;
            } else if(sum[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }
        if(sum[l] >= target) {
            return l;
        } else {
            return r;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

// map solution

class Solution {
public:
    map<int, int> mp;
    int sum;
    Solution(vector<int> w) {
        sum = 0;
        for(int i = 0; i < w.size(); ++i) {
            sum += w[i];
            mp[sum] = i;
        }
    }
    
    int pickIndex() {
        if(sum == 0) return 0;
        int value = rand() % sum + 1;
        return mp.lower_bound(value)->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */