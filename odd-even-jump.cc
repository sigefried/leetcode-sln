class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        
        vector<int> odd(n, 0);
        vector<int> even(n, 0);
        odd[n-1] = 1;
        even[n-1] = 1;
        vector<int> idx(n);
        for(int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            if( A[x] == A[y] ) {
                return x < y;
            }
            return A[x] < A[y];
        } );
        vector<int> oddnext = create(idx);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            if(A[x] == A[y]) {
                return x < y;
            }
            return A[x] > A[y];
        } );
        vector<int> evennext = create(idx);
        
        for(int i = n - 2; i >= 0; i--) {
            if (oddnext[i] != -1) {
                odd[i] = even[oddnext[i]];
            }
            if(evennext[i] != -1) {
                even[i] = odd[evennext[i]];
            }
        }
        
        int ret = 0;
        for(auto n : odd) {
            ret += n;
        }
        return ret;
    }
    
    vector<int> create(vector<int> &idx) {
        vector<int> next(idx.size(), -1);
        stack<int> stk;
        for(int n : idx) {
            while(!stk.empty() && n > stk.top()) {
                next[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        } 

        return next;
    }
};