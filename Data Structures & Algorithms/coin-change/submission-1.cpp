class Solution {
   public:
    int coinChange(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (index == coins.size() || amount < 0) return INT_MAX;
        if (dp[index][amount] != -1) return dp[index][amount];
        int include = coinChange(coins, amount - coins[index], index, dp);
        int exclude = coinChange(coins, amount, index + 1, dp);
        dp[index][amount] = min((include == INT_MAX) ? include : 1 + include, exclude);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        // int res = coinChange(coins, amount, 0, dp);
        // if (res == INT_MAX) return -1;
        // return res;
        for (int i = 1; i <= amount; i++) {
            dp[0][i] = INT_MAX;
        }
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                int include =
                    (dp[i][j - coins[i - 1]] == INT_MAX) ? INT_MAX : 1 + dp[i][j - coins[i - 1]];
                dp[i][j] = min(include, dp[i - 1][j]);
            }
        }
        if (dp[coins.size()][amount] == INT_MAX) return -1;
        return dp[coins.size()][amount];
    }
};
