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
    int result = 0;

private: 
    void dfs(TreeNode* root, int& count)
    {
        if (!root) return;

        dfs(root->left, count);
        if (count == 0) return;

        --count;
        if (count == 0)
        {
            result = root->val;
            return;
        }

        dfs(root->right, count);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        dfs(root, count);
        return result;
    }
};
