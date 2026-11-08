class Solution {
   public:
    void permute(vector<int>& nums, vector<vector<int>>& result, vector<int> permutation, int index,
                 int& n) {
        if (index == n) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (permutation[i] == INT_MAX) {
                permutation[i] = nums[index];
                permute(nums, result, permutation, index + 1, n);
                permutation[i] = INT_MAX;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> permutation(n, INT_MAX);
        permute(nums, result, permutation, 0, n);
        return result;
    }
};
