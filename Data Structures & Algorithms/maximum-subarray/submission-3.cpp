class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxVal = -INT_MAX;
        int sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            maxVal = max(maxVal, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxVal;
    }
};
