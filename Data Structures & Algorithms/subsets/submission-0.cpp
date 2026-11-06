class Solution {
   public:
    void dfs(vector<int>& nums, int index, vector<vector<int>>& result, vector<int>& path) {
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        dfs(nums, index + 1, result, path);
        path.pop_back();
        dfs(nums, index + 1, result, path);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, result, path);
        return result;
    }
};
