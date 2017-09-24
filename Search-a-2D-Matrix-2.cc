class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int i = m - 1, j = 0;
        while (i >= 0 && i < m && j >=0 && j < n) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) {
                j++;
            } else {
                // > target
                i--;
            }
        }
        return false;
    }
};