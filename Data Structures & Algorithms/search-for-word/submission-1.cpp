class Solution {
   public:
    bool backtrack(vector<vector<char>>& board, string word, int index, int r, int c, int& ROWS,
                   int& COLS) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || index >= word.size() ||
            board[r][c] != word[index])
            return false;

        // cout << r << " " << c << " " << index << " " << word[index] << endl;
        if (index == word.size() - 1) return true;
        char temp = board[r][c];
        board[r][c] = '.';
        bool res = backtrack(board, word, index + 1, r + 1, c, ROWS, COLS) ||
                   backtrack(board, word, index + 1, r - 1, c, ROWS, COLS) ||
                   backtrack(board, word, index + 1, r, c + 1, ROWS, COLS) ||
                   backtrack(board, word, index + 1, r, c - 1, ROWS, COLS);
        board[r][c] = temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size(), COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (backtrack(board, word, 0, i, j, ROWS, COLS)) return true;
            }
        }
        return false;
    }
};
