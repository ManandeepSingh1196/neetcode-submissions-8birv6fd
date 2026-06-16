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

class Solution {
private: 
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (max(p->val, q->val) < root->val)
            return lca(root->left, p, q);

        else if (min(p->val, q->val) > root->val)
            return lca(root->right, p, q);

        else
            return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

        return lca(root, p, q);
    }
};
