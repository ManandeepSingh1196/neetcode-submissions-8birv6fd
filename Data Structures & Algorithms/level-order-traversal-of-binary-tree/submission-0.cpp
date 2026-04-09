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
typedef vector<vector<int>> nest;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        nest result;
        if (!result.empty()) return result;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;

            for (int idx = q.size(); idx > 0; --idx)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if (!level.empty()) 
                result.push_back(level);
        }
        return result;
    }

};
