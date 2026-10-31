class Solution {
   public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto nei : graph[node]) {
            dfs(graph, nei, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                count++;
            }
        }
        return count;
    }
};
