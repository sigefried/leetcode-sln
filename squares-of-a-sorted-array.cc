class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n - 1;
        vector<int> ret(n, 0);
        for(int k = A.size() - 1; k >= 0; --k) {
            if(abs(A[l]) > abs(A[r]) ) {
                ret[k] = A[l] * A[l];
                l++;
            } else {
                ret[k] = A[r] * A[r];
                r--;
            }
        }
        return ret;
    }
};