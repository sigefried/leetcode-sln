class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<pair<int,int>,  int> count; // move vector - > count
        vector<pair<int,int>> a, b;
        int m = A.size();
        int n = A[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(A[i][j] == 1) {
                    a.push_back({i,j});
                }
                if(B[i][j] == 1) {
                    b.push_back({i,j});
                }
            }
        }
        
        int ret = 0;
        for(auto p : a) {
            for(auto q : b) {
                pair<int,int> vec = {p.first - q.first, p.second - q.second};
                count[vec] += 1;
                ret = max(ret, count[vec]);
            }
        }
        return ret;
    }
};