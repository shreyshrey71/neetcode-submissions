class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });
        vector<int> interval = intervals[0];
        vector<vector<int>> result;
        for (int i = 1; i < intervals.size(); i++) {
            if (interval[1] < intervals[i][0]) {
                result.push_back(interval);
                interval = intervals[i];
            } else {
                interval[1] = max(interval[1], intervals[i][1]);
                interval[0] = min(interval[0], intervals[i][0]);
            }
        }
        result.push_back(interval);
        return result;
    }
};
