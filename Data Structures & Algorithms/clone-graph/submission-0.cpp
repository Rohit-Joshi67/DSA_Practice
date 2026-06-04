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
        unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)   //null handling
        return nullptr;
       if (mp.count(node)) // copy handling
            return mp[node];
        mp[node]= new Node(node->val); //made new node
        for(auto nbr :node->neighbors)
        mp[node]->neighbors.push_back(cloneGraph(nbr));//clone all neighbours

        return mp[node];
    }
};
