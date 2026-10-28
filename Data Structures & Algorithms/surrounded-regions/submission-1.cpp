class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 'O') return;
        grid[r][c] = 'T';
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
    }
    void solve(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            if (grid[i][0] == 'O') dfs(grid, i, 0);
            if (grid[i][COLS - 1] == 'O') dfs(grid, i, COLS - 1);
        }
        for (int i = 0; i < COLS; i++) {
            if (grid[0][i] == 'O') dfs(grid, 0, i);
            if (grid[ROWS - 1][i] == 'O') dfs(grid, ROWS - 1, i);
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 'T') grid[i][j] = 'O';
            }
        }
    }
};
