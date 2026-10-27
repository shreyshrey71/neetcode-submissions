/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) return node;
        if (visited.find(node) != visited.end()) return visited[node];
        Node* newNode = new Node(node->val);
        visited[node] = newNode;
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, visited));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        // return dfs(node, visited);
        // bfs starts here
        if (!node) return node;
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
