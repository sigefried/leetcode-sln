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

// pq
class record {
public:
    int x;
    int y;
    int val;
    record(int x, int y, int val) : x(x), y(y), val(val) {
        
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        auto cmp = [](record &a, record &b) {
            return a.val > b.val;
        };
        priority_queue<record, vector<record>, decltype(cmp) > pq(cmp);
        for(int j = 0; j < n; ++j) {
            pq.push(record(0,j,matrix[0][j]));
        }
        for(int i = 0; i < k-1; ++i) {
            record cur = pq.top();
            pq.pop();
            if(cur.x == m - 1) continue;
            pq.push(record(cur.x + 1, cur.y, matrix[cur.x + 1][cur.y]));
        }
        
        return pq.top().val;
    }
};