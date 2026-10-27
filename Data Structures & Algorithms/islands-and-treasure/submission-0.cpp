class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), distance = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        vector<pair<int, int>> nd = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while (!q.empty()) {
            int processCells = q.size();
            distance++;
            for (int i = 0; i < processCells; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int j = 0; j < nd.size(); j++) {
                    int nr = r + nd[j].first;
                    int nc = c + nd[j].second;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == INT_MAX) {
                        grid[nr][nc]=distance;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
