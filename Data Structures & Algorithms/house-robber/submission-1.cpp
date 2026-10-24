class Solution {
   public:
    int dfs(vector<int> nums, int n, vector<int>& memo) {
        if (n < 0) return 0;
        if (memo[n] != -1) return memo[n];
        memo[n] = max(nums[n] + dfs(nums, n - 2, memo), dfs(nums, n - 1, memo));
        return memo[n];
    }
    int rob(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return dfs(nums, nums.size() - 1, memo);
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
