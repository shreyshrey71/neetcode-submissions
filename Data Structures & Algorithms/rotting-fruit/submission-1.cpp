class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), time = 0;
        // vector<vector<bool>> visited(ROWS, vector<int>(COLS, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        while (!q.empty()) {
            int newRottenCount = q.size();
            int rotCount = 0;
            while (newRottenCount > 0) {
                newRottenCount--;
                auto [r, c] = q.front();
                q.pop();
                grid[r][c] = 2;
                for (int i = 0; i < directions.size(); i++) {
                    int nr = r + directions[i].first;
                    int nc = c + directions[i].second;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        rotCount++;
                    }
                }
            }
            if (rotCount != 0) time++;
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
