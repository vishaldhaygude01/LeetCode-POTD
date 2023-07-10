class Solution
{
public:
    int minDepth(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (!root->left)
            return minDepth(root->right) + 1;
        if (!root->right)
            return minDepth(root->left) + 1;
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};