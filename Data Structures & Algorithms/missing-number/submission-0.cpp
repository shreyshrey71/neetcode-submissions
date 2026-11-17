class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) res ^= num;
        for (int i = 1; i <= nums.size(); i++) res ^= i;
        return res;
    }
};
