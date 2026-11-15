class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        // vector<int> dp(n, 1e9);
        // dp[n - 1] = 0;
        // for (int i = n - 2; i >= 0; i--) {
        //     for (int j = 1; j <= nums[i] && i + j < n; j++) {
        //         dp[i] = min(dp[i], dp[i + j]);
        //     }
        //     dp[i]++;
        // }
        // return dp[0];
        vector<int> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;
        while (!q.empty()) {
            auto [node, dist] = q.front();
            // cout << node << " " << dist << endl;
            q.pop();
            if (node + nums[node] >= n - 1) return dist + 1;
            for (int i = 1; i <= nums[node]; i++) {
                if (!visited[node + i]) {
                    q.push({i + node, dist + 1});
                    visited[i + node] = true;
                }
            }
        }
        return -1;
    }
};
