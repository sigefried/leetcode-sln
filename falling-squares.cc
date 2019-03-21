class SegmentTree {
public:
    SegmentTree* left;
    SegmentTree* right;
    int val;
    int begin;
    int end;
    
    SegmentTree(int begin, int end, int val) : begin(begin), end(end), val(val) {
        left = nullptr;
        right = nullptr;
    }
    
    void remove(SegmentTree * &cur) {
        if(cur == nullptr) return;
        remove(cur->left);
        remove(cur->right);
        delete cur;
        cur = nullptr;
    }
    
    void insert(int a, int b, int v) {
        if (a<=begin && b>=end)
        {
            remove(left);
            remove(right);
            val = v;
            return;
        }
        if (a>=end || b<=begin)
            return;
        if (left==nullptr)
        {
            int mid = (end-begin)/2+begin;
            left = new SegmentTree(begin,mid,val);
            right = new SegmentTree(mid,end,val);
        }
        left->insert(a,b,v);
        right->insert(a,b,v);
        val = max(left->val,right->val);
        return;
        
    }
    
    int get_val(int a, int b) {
        if(a<= begin && b >= end) {
            return this->val;
        }
        if(a >= end || b <= begin) {
            return 0;
        }
        
        if(this->left == nullptr) {
            return this->val;
        }
        int l = this->left->get_val(a,b);
        int r = this->right->get_val(a,b);
        return max(l,r);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        SegmentTree root = SegmentTree(0,1e9,0);
        vector<int> ret;
        int curMax = 0;
        for(auto p :positions) {
            int cur = root.get_val(p.first,p.first+p.second);
            //cout << cur << endl;
            //int cur  = 10;
            curMax = max(curMax, cur+p.second);
            root.insert(p.first,p.first+p.second, cur+p.second);  
            ret.push_back(curMax);
        }
        return ret;
    }
};