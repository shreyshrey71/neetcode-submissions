class Solution {
   public:
    vector<vector<int>> dp;
    int rec(vector<int>& prices, int index, bool have) {
        if (index >= prices.size()) return 0;
        if (have) {
            if (dp[index][0] != -1) return dp[index][0];
            dp[index][0] =
                max(rec(prices, index + 2, false) + prices[index], rec(prices, index + 1, true));
            return dp[index][0];
        } else {
            if (dp[index][1] != -1) return dp[index][1];
            dp[index][1] =
                max(rec(prices, index + 1, true) - prices[index], rec(prices, index + 1, false));
            return dp[index][1];
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(), vector<int>(2, -1));
        return rec(prices, 0, false);
    }
};
