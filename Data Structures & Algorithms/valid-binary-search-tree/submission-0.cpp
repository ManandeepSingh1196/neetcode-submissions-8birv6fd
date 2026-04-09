class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* node, long left, long right)
    {
        if (!node) return true;

        if (!(node->val > left && node->val < right)) return false;

        return isValid(node->left, left, node->val) && isValid(node->right, node->val, right);
    }
};
