/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string serial;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) 
        {
            TreeNode* node = que.front();
            que.pop();

            if (!node)
                serial += "N,";
            else {
                serial+= to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }

        return serial;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream stream(data);
        string curr;

        getline(stream, curr, ',');
        if (curr == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(curr));
        
        queue<TreeNode*> que;
        que.push(root);

        while(getline(stream, curr, ','))
        {
            TreeNode* node = que.front();
            que.pop();
            if (curr != "N")
            {
                node->left = new TreeNode(stoi(curr));
                que.push(node->left);
            }

            getline(stream, curr, ',');
            if(curr != "N")
            {
                node->right = new TreeNode(stoi(curr));
                que.push(node->right);
            }
        }

        return root;
    }
};
