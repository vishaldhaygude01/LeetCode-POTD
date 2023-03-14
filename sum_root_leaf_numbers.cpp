class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return sumTree(root, 0);
    }
    int sumTree(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return 0;
        }
        val = (val * 10 + root->val);
        if (root->left == NULL && root->right == NULL)
        {
            return val;
        }
        return sumTree(root->left, val) +
               sumTree(root->right, val);
    }
};