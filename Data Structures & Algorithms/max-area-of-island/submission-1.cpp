class Solution {
   public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 ||
            visited[r][c])
            return 0;
        visited[r][c] = true;
        return 1 + dfs(grid, r, c + 1, visited) + dfs(grid, r, c - 1, visited) +
               dfs(grid, r - 1, c, visited) + dfs(grid, r + 1, c, visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), maxArea = 0;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    maxArea = max(maxArea, dfs(grid, i, j, visited));
            }
        }
        return maxArea;
    }
};
