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
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int res = coinChange(coins, amount, 0, dp);
        if (res == INT_MAX) return -1;
        return res;
    }
};
