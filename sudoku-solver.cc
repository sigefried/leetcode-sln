class Solution {
public:
    int m, n;
    void solveSudoku(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        if(n == 0) return;
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c; 
                            if(solve(board))
                                return true; 
                            else
                                board[i][j] = '.'; 
                        }
                    }
                    return false;
                }
            
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false; 
            if(board[row][i] != '.' && board[row][i] == c) return false; 
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; 
        }
        return true;
    }    
};