class Solution {
   public:
    void backtrack(vector<int> nums, int i, int target, vector<int>& path,
                   vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (i == nums.size() || target < 0) return;
        path.push_back(nums[i]);
        backtrack(nums, i, target - nums[i], path, result);
        path.pop_back();
        backtrack(nums, i + 1, target, path, result);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, target, path, result);
        return result;
    }
};
