class Solution {
   public:
    int lis(vector<int> nums, int index, int lastVal, vector<unordered_map<int, int>>& dp) {
        if (index >= nums.size()) return 0;
        if (dp[index].count(lastVal)) return dp[index][lastVal];
        if (nums[index] <= lastVal) {
            dp[index][lastVal] = lis(nums, index + 1, lastVal, dp);
            return dp[index][lastVal];
        }
        dp[index][lastVal] = max(lis(nums, index + 1, lastVal, dp), 1 + lis(nums, index + 1, nums[index], dp));
        return dp[index][lastVal];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<unordered_map<int, int>> dp(nums.size());
        return lis(nums, 0, INT_MIN, dp);
    }
};
