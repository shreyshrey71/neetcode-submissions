class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Convert edges to adjacency list of pair of nodes and time
        vector<vector<pair<int, int>>> al(n + 1, vector<pair<int, int>>());
        for (const auto& time : times) {
            // storing ti before vi so priority queue sorting is easy and dont have to use custom
            // comparator
            al[time[0]].emplace_back(time[2], time[1]);
        }
        // Create a visited array for nodes
        vector<bool> visited(n + 1, false);
        // Create a priority queue for bfs, but to execute the non visited with lesser times with
        // higher priority
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        // Do the bfs, update the time for the branch when inserting neighbors, so priority queue
        // can enable our logic
        int time = 0;
        while (!pq.empty()) {
            auto tn = pq.top();
            pq.pop();
            int node = tn.second;
            if (visited[node]) continue;
            time = tn.first;
            visited[node] = true;
            for (auto tnei : al[node]) {
                int nei = tnei.second;
                int t1 = tnei.first + time;
                if (!visited[nei]) {
                    pq.push({t1, nei});
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (!visited[i]) return -1;
        // Once completed return last time processed node time
        return time;
    }
};
