class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int r, int c, int ROWS, int COLS,
             vector<vector<int>>& visited) {
        visited[r][c] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == '1' &&
                visited[nr][nc] == 0)
                dfs(grid, nr, nc, ROWS, COLS, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    dfs(grid, i, j, ROWS, COLS, visited);
                    // bfs(grid, i, j, ROWS, COLS, visited);
                    count++;
                }
            }
        }
        return count;
    }
};
