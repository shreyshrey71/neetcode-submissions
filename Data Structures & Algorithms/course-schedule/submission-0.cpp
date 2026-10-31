class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> inorder(numCourses, 0);
        for (auto prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
            inorder[prerequisite[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nei : graph[node]) {
                inorder[nei]--;
                if (inorder[nei] == 0) q.push(nei);
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] != 0) return false;
        }
        return true;
    }
};
