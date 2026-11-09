class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int r = 1, n = nums.size();
        int maxVal = nums[0];
        int sum = nums[0];
        for (int r = 1; r < n; r++) {
            maxVal = max(maxVal, nums[r]);
            if (nums[r] >= 0) {
                sum += nums[r];
                maxVal = max(maxVal, sum);
            } else {
                if (sum + nums[r] > 0) {
                    sum += nums[r];
                } else {
                    maxVal = max(maxVal, nums[r]);
                    sum = 0;
                }
            }
        }
        return maxVal;
    }
};
