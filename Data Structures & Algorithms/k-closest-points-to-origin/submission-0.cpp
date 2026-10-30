class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto point : points) {
            int x = point[0], y = point[1];
            double distance = sqrt(x * x + y * y);
            pq.push({distance, {x, y}});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            vector<int> r(2, 0);
            r[0] = p.second.first;
            r[1] = p.second.second;
            result.push_back(r);
        }
        return result;
    }
};
