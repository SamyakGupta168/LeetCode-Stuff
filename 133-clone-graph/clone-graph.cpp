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
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto adjNode : node->neighbors) {
            if(!mp.count(adjNode)) newNode->neighbors.push_back(cloneGraph(adjNode));
            else newNode->neighbors.push_back(mp[adjNode]);
        }
        return newNode;
    }
};