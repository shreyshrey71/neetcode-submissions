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
    unordered_map<Node*, Node*> visited;
    void dfs(Node* newNode, Node* node) {
        if (visited.contains(node)) return;
        visited[node] = newNode;
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (visited.contains(node)) return visited[node];
        Node* newNode = new Node(node->val);
        dfs(newNode, node);
        return newNode;
    }
};
