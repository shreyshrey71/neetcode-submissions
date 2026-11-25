class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> flightMap(n, vector<pair<int, int>>());
        vector<vector<int>> visited(n, vector<int>(k + 2, INT_MAX));
        for (auto flight : flights) {
            flightMap[flight[0]].emplace_back(flight[1], flight[2]);
        }
        auto cmp = [](auto& a, auto& b) {
            auto [a1, a2, a3] = a;
            auto [b1, b2, b3] = b;
            return a2 > b2;
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq;
        pq.push({src, 0, k + 1});
        for (int i = 0; i <= k + 1; i++) visited[src][i] = 0;
        int minCost = INT_MAX;
        while (!pq.empty()) {
            auto [node, cost, stopsLeft] = pq.top();
            pq.pop();
            if (node == dst) {
                minCost = min(minCost, cost);
                continue;
            }
            if (stopsLeft == 0) continue;
            for (auto [nei, price] : flightMap[node]) {
                if (visited[nei][stopsLeft] < cost + price) continue;
                pq.push({nei, cost + price, stopsLeft - 1});
                for (int i = 0; i <= stopsLeft; i++)
                    visited[nei][i] = min(visited[nei][i], cost + price);
            }
        }
        if (minCost == INT_MAX) return -1;
        return minCost;
    }
};
