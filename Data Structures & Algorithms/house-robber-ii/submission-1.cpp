class Solution {
   public:
    int rob(vector<int>& nums) {
        // Run 2 DPs.
        //  #1 from 0 to n-2
        //  #2 from 1 to n-1
        //  Because Last and 1st elemt cannot be used simultaneously.
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int rob1 = 0, rob2 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        int max1 = rob2;
        rob1 = 0;
        rob2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return max(max1, rob2);
    }
};
