
class Solution
{
public:
    int maxPath = 0;

    void solve(TreeNode *root, int left, int right)
    {
        if (!root)
            return;

        maxPath = max({maxPath, left, right});

        solve(root->left, right + 1, 0);
        solve(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode *root)
    {
        solve(root, 0, 0);
        return maxPath;
    }
};