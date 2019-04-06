class BIT {
public:
    vector<int> bit;
    int sz;
    BIT(int n) {
        sz = n + 1;
        for(int i = 0; i < sz; ++i) {
            bit.push_back(0);
        }
    }
    
    void update(int idx) {
        while(idx < sz) {
            bit[idx] += 1;
            idx += low_bit(idx);
        }
    }
    
    int sum(int idx) {
        int ret = 0;
        while(idx > 0) {
            ret += bit[idx];
            idx -= low_bit(idx);
        }
        return ret;
    }
    
    int low_bit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return {};
        BIT b(n);
        
        auto tmp = nums;
        sort(tmp.begin(), tmp.end());
        map<int,int> compress;
        for(int i = 0; i < n; ++i) {
            compress[tmp[i]] = i + 1;
        }
        vector<int> ret(n);
        for(int i = n - 1; i >= 0; --i) {
            ret[i] = b.sum(compress[nums[i]] - 1);
            b.update(compress[nums[i]]);
        }
        return ret;
    }
};