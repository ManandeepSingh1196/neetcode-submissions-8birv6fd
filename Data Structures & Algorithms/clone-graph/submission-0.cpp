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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }

private: 
    Node* dfs(Node* root, auto& mp)
    {
        if (root == NULL) return nullptr;

        if (mp.find(root) == mp.end())
        {
            mp[root] = new Node(root->val, {});

            for (auto& neighbour: root->neighbors)
                mp[root]->neighbors.push_back(dfs(neighbour, mp));
        }

        return mp[root];
    }
};
