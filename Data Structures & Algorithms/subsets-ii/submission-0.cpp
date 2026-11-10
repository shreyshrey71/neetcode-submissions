class Solution {
   public:
    void backtrack(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int index) {
        if (index >= nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        backtrack(nums, subset, result, index + 1);
        subset.pop_back();
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }
        backtrack(nums, subset, result, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, subset, result, 0);
        return result;
    }
};
