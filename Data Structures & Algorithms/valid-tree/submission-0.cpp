class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nei : graph[node]) {
                if (!visited[nei]) {
                    q.push(nei);
                    visited[nei] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
