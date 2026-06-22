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
private:
    Node* rec(Node* node, unordered_map<Node*, Node*>& ogCloneMap) {
        if(node == nullptr) {
            return nullptr;
        }
        if (ogCloneMap.count(node)) {
            return ogCloneMap[node];
        }

        Node* clonedNode = new Node(node->val);
        ogCloneMap[node] = clonedNode;

        for(int i = 0; i < node->neighbors.size(); i++) {
            Node* clonedNeighbor = rec(node->neighbors[i], ogCloneMap);
            clonedNode->neighbors.push_back(clonedNeighbor);
        }

        return clonedNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> ogCloneMap;

        Node* clonedGraph = rec(node, ogCloneMap);

        return clonedGraph;
    }
};
