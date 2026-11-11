class Solution {
   public:
    int dfs(vector<int>& nums, int index, int total, int& target, int n,
            vector<vector<vector<int>>>& dp) {
        if (index == n) return (target == total) ? 1 : 0;
        if (total < 0) {
            int val = dp[index][-1 * total][1];
            if (val != -1) return val;
            val = dfs(nums, index + 1, total + nums[index], target, n, dp) +
                  dfs(nums, index + 1, total - nums[index], target, n, dp);
            dp[index][-1 * total][1] = val;
            return val;
        }
        int val = dp[index][total][0];
        if (val != -1) return val;
        val = dfs(nums, index + 1, total + nums[index], target, n, dp) +
              dfs(nums, index + 1, total - nums[index], target, n, dp);
        dp[index][total][0] = val;
        return val;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int m = 0;
        for (const int& num : nums) {
            m += abs(num);
        }
        vector<vector<vector<int>>> dp(nums.size(),
                                       vector<vector<int>>(m + 1, vector<int>(2, -1)));
        return dfs(nums, 0, 0, target, nums.size(), dp);
    }
};
