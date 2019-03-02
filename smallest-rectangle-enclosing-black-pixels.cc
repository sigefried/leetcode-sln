class Solution {
public:
    vector<vector<char>> image;
    int m,  n;
    int minArea(vector<vector<char>>& image, int x, int y) {
        this->image = image;
        m = image.size();
        if(m == 0) return 0;
        n = image[0].size();
        if(n == 0) return 0;
        int top = search_row(0, x, true);
        int down = search_row(x + 1, m, false);
        int left = search_col(0, y, true);
        int right = search_col(y + 1, n, false);
        return (right - left) * (down - top);
    }
    
    int search_row(int l, int r, bool opt) {
        int col;
        while(l < r) {
            col = 0;
            int mid = (l + r) >> 1;
            while(col < n && image[mid][col] == '0') col++;
            if(col < n == opt) {
                // exist
                r = mid;
            } else {
                l = mid + 1;
            }
            
        }
        cout << l << endl;
        return l;
    }

    int search_col(int l, int r, bool opt) {
        int row;
        while(l < r) {
            row = 0;
            int mid = (l + r) >> 1;
            while(row < m && image[row][mid] == '0') {
                row++;
            } 
            if(row < m == opt) {
                // exist
                r = mid;
            } else {
                l = mid + 1;
            }
            
        }
        cout << l << endl;
        return l;
    }
};