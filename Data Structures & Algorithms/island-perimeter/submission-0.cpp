class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), perimeter = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    break;
                }
            }
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto cell = q.front();
            int r = cell.first;
            int c = cell.second;
            perimeter += 4;
            q.pop();
            for (auto nd : directions) {
                int nr = r + nd.first;
                int nc = c + nd.second;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    perimeter--;
                    if (!visited[nr][nc]) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
        }
        return perimeter;
    }
};