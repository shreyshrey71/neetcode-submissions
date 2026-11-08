class Solution {
   public:
    void findSubSets(vector<vector<int>>& result, vector<int>& v, vector<int>& subset, int index,
                     int target) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }
        if (index == v.size() || target < 0) return;
        subset.push_back(v[index]);
        findSubSets(result, v, subset, index + 1, target - v[index]);
        subset.pop_back();
        while (index < v.size() - 1 && v[index + 1] == v[index]) index++;
        findSubSets(result, v, subset, index + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        findSubSets(result, candidates, subset, 0, target);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
