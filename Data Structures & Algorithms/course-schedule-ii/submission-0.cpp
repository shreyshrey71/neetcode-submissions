class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inorder(numCourses, 0);
        vector<int> result;
        for (auto prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inorder[prerequisite[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) q.push(i);
        }
        if (q.empty()) return result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto nei : graph[node]) {
                inorder[nei]--;
                if (inorder[nei] == 0) q.push(nei);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] != 0) return vector<int>();
        }
        return result;
    }
};
