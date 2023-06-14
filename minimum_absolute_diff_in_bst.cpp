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
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> num;
        inOrder(root, num);
        int res = INT_MAX;
        for (int i = 1; i < num.size(); i++)
        {
            res = min(res, (num[i] - num[i - 1]));
        }
        return res;
    }
};