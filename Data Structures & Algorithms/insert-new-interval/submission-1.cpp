class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int it = 0;
        for (; it < n && intervals[it][1] < newInterval[0]; it++) result.push_back(intervals[it]);

        for (; it < n && intervals[it][0] <= newInterval[1]; it++) {
            newInterval[0] = min(newInterval[0], intervals[it][0]);
            newInterval[1] = max(newInterval[1], intervals[it][1]);
        }
        result.push_back(newInterval);
        for (; it < n; it++) {
            result.push_back(intervals[it]);
        }
        return result;
    }
};
