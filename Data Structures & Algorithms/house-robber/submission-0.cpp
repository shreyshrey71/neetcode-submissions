class Solution {
   public:
    int dfs(vector<int> nums, int n, vector<int>& memo) {
        if (n < 0) return 0;
        if (memo[n] != -1) return memo[n];
        memo[n] = max(nums[n] + dfs(nums, n - 2, memo), dfs(nums, n - 1, memo));
        return memo[n];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dfs(nums, nums.size() - 1, memo);
    }
};
