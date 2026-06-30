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
    Node* dfs(Node* node, map<Node*, Node*> &mp) {
        if(node == nullptr) return nullptr;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        auto &v = node->neighbors;
        auto &ref = newNode->neighbors;
        for(auto it : v) {
            if(!mp.count(it)) {
                ref.push_back(dfs(it, mp));
            } else {
                ref.push_back(mp[it]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};