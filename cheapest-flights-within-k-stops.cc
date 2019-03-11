class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> d(n, INT_MAX / 2);
        d[src] = 0;
        for(int cnt = 0; cnt <= K; ++cnt) {
            vector<int> D(d);
            for(auto f : flights) {
                if(d[f[0]] + f[2] < D[f[1]]) {
                    D[f[1]] = d[f[0]] + f[2]; 
                }
            }
            d = D;
        }
        
        return d[dst] == INT_MAX / 2 ? -1 : d[dst];
    }
};