class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diag;
    int adiag;
    int sz;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        diag = 0;
        adiag = 0;
        rows.resize(n);
        cols.resize(n);
        sz = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1) {
            rows[row]++;
            cols[col]++;
            if(row == col) {
                diag++;
            }
            if(row == sz - col - 1) {
                adiag++;
            }
            if(rows[row] == sz || cols[col] == sz || diag == sz || adiag == sz) {
                return 1;
            }
            
        } else if(player == 2) {
            rows[row]--;
            cols[col]--;
            if(row == col) {
                diag--;
            }
            if(row == sz -1 -col) {
                adiag--;
            }
            if(rows[row] == -sz || cols[col] == -sz || diag == -sz || adiag == -sz) {
                return 2;
            }            
            
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */