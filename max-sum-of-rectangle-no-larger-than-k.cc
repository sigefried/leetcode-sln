class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        int ret = INT_MIN;
        for(int l = 0; l < n; ++l) {
            vector<int> sums(m,0);
            for(int r = l; r < n; ++r) {
                for(int i = 0; i < m; ++i) {
                    sums[i] += matrix[i][r];
                }
            
                set<int> prevSums;
                prevSums.insert(0);
                int accu = 0;
                int localMax = INT_MIN;
                for(auto sum : sums) {
                    accu += sum;
                    //cout << accu << endl;
                    auto it = prevSums.lower_bound(accu - k);
                    if(it != prevSums.end()) {
                        localMax = max(localMax, accu - *it);
                    }
                    prevSums.insert(accu);
                }
                ret = max(ret, localMax);
            }
        }
        return ret;
    }
};