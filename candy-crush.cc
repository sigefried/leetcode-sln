class Solution
{
  public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        bool changed = false;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j + 2 < col; ++j)
            {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i][j + 1]) && val == abs(board[i][j + 2]))
                {
                    board[i][j] = -val;
                    board[i][j + 1] = -val;
                    board[i][j + 2] = -val;
                    changed = true;
                }
            }
        }
        for (int j = 0; j < col; ++j)
        {
            for (int i = 0; i + 2 < row; ++i)
            {
                int val = abs(board[i][j]);
                if (val != 0 && val == abs(board[i + 1][j]) && val == abs(board[i + 2][j]))
                {
                    board[i][j] = -val;
                    board[i + 1][j] = -val;
                    board[i + 2][j] = -val;
                    changed = true;
                }
            }
        }
        if (changed)
        {
            for (int j = 0; j < col; ++j)
            {
                int bottom = row - 1;
                for (int i = row - 1; i >= 0; --i)
                {
                    if (board[i][j] > 0)
                    {
                        board[bottom--][j] = board[i][j];
                    }
                }
                while (bottom >= 0)
                    board[bottom--][j] = 0;
            }
        }

        return changed ? candyCrush(board) : board;
    }
};