class Solution {
   public:
    bool canJumpFrom(vector<int>& nums, int n, vector<bool>& dp) {
        if (n >= nums.size() - 1) {
            if (n == nums.size() - 1) dp[n] = true;
            return true;
        }
        if (nums[n] == 0) {
            return false;
        }
        if (dp[n]) return true;
        bool canJumpBool = false;
        for (int i = 0; i < nums[n] && !canJumpBool; i++) {
            canJumpBool = canJumpBool || canJumpFrom(nums, n + i, dp);
        }
        dp[n] = canJumpBool;
        return canJumpBool;
    }
    bool canJump(vector<int>& nums) {
        // vector<bool> dp(nums.size(), false);
        // dp[nums.size() - 1] = true;
        // for (int i = nums.size() - 2; i >= 0; i--) {
        //     for (int j = 1; j <= nums[i] && !dp[i]; j++) {
        //         dp[i] = dp[i] || dp[i + j];
        //     }
        // }
        // return dp[0];
        int goal = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] + i >= goal) goal = i;
        }
        return (goal == 0);
    }
};
