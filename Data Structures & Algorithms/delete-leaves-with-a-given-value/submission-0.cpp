class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }

    TreeNode* dfs(TreeNode* root, int target) 
    {
        if (!root) return nullptr;

        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        if (!root->left && !root->right && root->val == target)
            return nullptr;

        return root;
    }
};