class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ret = 0;
        int n = A.size();
        int m = A[0].size();
        vector<bool> sorted(n-1, false);
        int j, i;
        for(j = 0; j < m; ++j) {
            for(i = 0; i < n - 1; ++i) {
                if(!sorted[i] && A[i][j] > A[i+1][j]) {
                    ret++;
                    break;
                }
            }
            if(i < n - 1) continue; // delete some char
            for(i = 0; i < n - 1; ++i) {
                if(A[i][j] < A[i+1][j]) {
                    sorted[i] = true;
                }
            }
        }
        return ret;
    }
};