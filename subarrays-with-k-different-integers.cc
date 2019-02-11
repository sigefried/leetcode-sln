class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int a =  atMostK(A, K);
        int b = atMostK(A, K - 1);
        return a - b;
    }
    int atMostK(vector<int>& A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        int bar = -1;
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (++count[A[i]] == 1) cnt++;
            while (cnt > K) {
                if (--count[A[++bar]] == 0) cnt--;
                
            }
            res += i - bar;
        }
        return res;
    }
        
};