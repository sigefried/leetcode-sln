class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        if(n == 0) return {};
        vector<int> ans;
        int l = 0, r = n - 1, t = 0, b = m - 1;
        int cnt = 0;
        int total = n * m;
        while(cnt < total) {
            // l -> r
            for(int j = l; j <= r; ++j) {
                ans.push_back(matrix[t][j]);
                cnt++;
            }
            t++;
            if(cnt >= total) break;
            // t -> b
            for(int i = t; i <= b; ++i) {
                ans.push_back(matrix[i][r]);
                cnt++;
            }
            r--;
            if(cnt >= total) break;
            //r->l
            for(int j = r; j >= l; --j) {
                ans.push_back(matrix[b][j]);
                cnt++;
            }
            if(cnt >= total) break;
            b--;
            //b->t
            for(int i = b; i >= t; --i) {
                ans.push_back(matrix[i][l]);
                cnt++;
            }
            if(cnt >= total) break;
            l++;
        }
        
        return ans;
    }
};