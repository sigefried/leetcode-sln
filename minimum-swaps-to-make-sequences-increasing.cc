class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n  = A.size();
        vector<int> swap(1001, n);
        vector<int> not_swap(1001, n);
        swap[0] = 1;
        not_swap[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(A[i] > A[i-1] && B[i] > B[i-1]) {
                not_swap[i] = not_swap[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            
            if(A[i] > B[i-1] && B[i] > A[i-1]) {
                swap[i] = min(swap[i], not_swap[i - 1] + 1);
                not_swap[i] = min(not_swap[i], swap[i-1]);
            }
        }
        return min(swap[n-1], not_swap[n-1]);
    }
    
};