class Solution {
public:
    vector<int> dx = {-1, 0, 1, -1, 1, 0, 1, -1};
    vector<int> dy = {-1, 1, 1, 0, -1, -1, 0, 1};
    int m,n;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        m = board.size();
        n = board[0].size();
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'E') return;
        int num = getBombs(board, x, y);
        if (num == 0) {
            board[x][y] = 'B';
            for(int d = 0; d < 8; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                dfs(board, nx, ny);
            }
        } else {
            board[x][y] = '0' + num;
        }
    }
    
    int getBombs(vector<vector<char>>& board, int x, int y) {
        int ret = 0;
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                int nx = x + i;
                int ny = y + j;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(board[nx][ny] == 'M') {
                    ret++;
                }
            }
        }
        return ret;
    }
};