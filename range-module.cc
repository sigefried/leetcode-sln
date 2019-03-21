class SegmentTree {
public:
    int start;
    int end;
    bool val;
    SegmentTree *left;
    SegmentTree *right;
    SegmentTree(int start, int end, bool val) : start(start), end(end), val(val) {
        left = nullptr;
        right = nullptr;
    }
    
    void remove(SegmentTree * &cur) {
        if(cur == nullptr) return;
        //remove(cur->left);
        //remove(cur->right);
        delete cur;
        cur = nullptr;
        return;
    }
    
    void insert(int a, int b, bool v) {
        if(a >= end || b <= start) {
            return;
        }
        
        if(a <= start && b >= end) {
            remove(left);
            remove(right);
            val = v;
            return;
        }
        
        if(left == nullptr) {
            int mid = start + (end - start) / 2;
            left = new SegmentTree(start, mid, val);
            right = new SegmentTree(mid, end, val);
        }
        
        left->insert(a, b, v);
        right->insert(a, b, v);
        val = left->val && right->val;
    }
    
    bool query(int a, int b) {
        if(a >= end || b <= start) {
            return true;
        }
        if(a <= start && b >= end) {
            return val;
        }
        
        if(left == nullptr) {
            return val;
        }
        return left->query(a,b) && right->query(a,b);
    }
};



class RangeModule {
public:
    SegmentTree root = SegmentTree(0, 1e9, false);
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        root.insert(left, right, true);
    }
    
    bool queryRange(int left, int right) {
        return root.query(left, right);
    }
    
    void removeRange(int left, int right) {
        root.insert(left, right, false);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */