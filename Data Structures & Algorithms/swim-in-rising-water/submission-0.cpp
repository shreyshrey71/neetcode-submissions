class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = max(grid[0][0], grid[n - 1][n - 1]);
        auto cmp = [](auto& x, auto& y) { return x.second > y.second; };
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cmp)> pq;
        pq.push({{0, 0}, grid[0][0]});
        grid[0][0] = -1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            auto [g, h] = pq.top();
            pq.pop();
            if (h > t) t = h;
            if (g.first == n - 1 && g.second == n - 1) return t;
            for (auto dir : directions) {
                int r = g.first + dir.first;
                int c = g.second + dir.second;
                if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == -1) continue;
                pq.push({{r, c}, grid[r][c]});
                grid[r][c] = -1;
            }
        }
        return t;
    }
};
