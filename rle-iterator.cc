class RLEIterator {
public:
    
    int idx;
    vector<int> num;
    RLEIterator(vector<int>& A) {
        this->num.swap(A);
        this->idx = 0;
    }
    
    int next(int n) {
        while(idx < num.size() && n > num[idx]) {
            n -= num[idx];
            idx += 2;
        }
        
        if(idx >= num.size()) {
            return -1;
        }
        
        num[idx] -= n;
        return num[idx+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */