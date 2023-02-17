class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &num)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left, num);
        num.push_back(root->val);
        inOrder(root->right, num);
    }
    int minDiffInBST(TreeNode *root)
    {
        vector<int> num;
        inOrder(root, num);
        int res = INT_MAX;
        for (int i = 1; i < num.size(); i++)
        {
            res = min(res, abs(num[i] - num[i - 1]));
        }
        return res;
    }
};