class Solution {
   public:
    void dfs(vector<vector<int>>& heights, int r, int c, int prev, vector<vector<bool>>& visited) {
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] ||
            heights[r][c] < prev)
            return;
        visited[r][c] = true;
        static const pair<int, int> directions[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto [dr, dc] : directions) {
            dfs(heights, r + dr, c + dc, heights[r][c], visited);
        }
    }
    void bfs(vector<vector<int>>& heights, int r, int c, int prev, vector<vector<bool>>& visited) {
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] ||
            heights[r][c] < prev)
            return;
        visited[r][c] = true;
        static const pair<int, int> directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            prev = heights[r][c];
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size() ||
                    visited[nr][nc] || heights[nr][nc] < prev)
                    continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        for (int i = 0; i < ROWS; i++) {
            bfs(heights, i, 0, -1, pacific);
            bfs(heights, i, COLS - 1, -1, atlantic);
        }
        for (int j = 0; j < COLS; j++) {
            bfs(heights, 0, j, -1, pacific);
            bfs(heights, ROWS - 1, j, -1, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};
