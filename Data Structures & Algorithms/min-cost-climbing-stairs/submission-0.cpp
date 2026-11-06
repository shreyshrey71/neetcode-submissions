class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 2);
        dp[n + 1] = 0;
        dp[n] = cost[n - 1];
        for (int i = n - 1; i > 0; i--) {
            dp[i] = cost[i - 1];
            dp[i] += min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[1], dp[2]);
    }
};
