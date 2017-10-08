class NumArray {
public:
    vector<int> tree;
    vector<int> orig;
    int lowbit(int x) {
        return x & (-x);    
    }
    
    NumArray(vector<int> nums) {
        this->orig = nums;
        this->tree = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            init(i, nums[i]);
        }
    }
    
    void init(int i, int val) {
        for (int idx = i + 1; idx <= orig.size(); idx += lowbit(idx)) {
            tree[idx] += val;
        } 
    }
    
    void update(int i, int val) {
        int delta = val - orig[i];
        orig[i] = val;
        for (int idx = i + 1; idx <= orig.size(); idx += lowbit(idx)) {
            tree[idx] += delta;
        }
        
    }
    
    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
    
    int sum(int i) {
        int ret = 0;
        for (int idx = i + 1; idx > 0; idx -= lowbit(idx)) {
            ret += tree[idx];
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */