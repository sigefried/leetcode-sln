class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                q.push(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};


//-----------------bsearch----------
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        int m  = -1;
        while (l < r) {
            m = (l + r) / 2;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                int c = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
                count += c;
            }
            if (count < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};