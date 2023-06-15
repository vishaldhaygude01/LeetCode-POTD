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
    int maxLevelSum(TreeNode *root)
    {
        int ans = INT_MIN;
        int level = 1;
        int lc = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int maxSum = 0;
            int len = q.size();
            while (len--)
            {
                TreeNode *current = q.front();
                maxSum += current->val;
                q.pop();
                if (current->left != NULL)
                {
                    q.push(current->left);
                }
                if (current->right != NULL)
                {
                    q.push(current->right);
                }
            }
            if (maxSum > ans)
            {
                ans = maxSum;
                level = lc;
            }
            lc++;
        }
        return level;
    }
};