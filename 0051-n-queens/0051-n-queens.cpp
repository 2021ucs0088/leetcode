class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        func(board, result, n, 0);
        return result;
    }

    bool isvalid(int row, int col, vector<string>& board) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void func(vector<string>& board, vector<vector<string>>& result, int n, int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isvalid(row, col, board)) {
                board[row][col] = 'Q';
                func(board, result, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
};
