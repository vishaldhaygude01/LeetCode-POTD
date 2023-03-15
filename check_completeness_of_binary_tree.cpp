class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                    if (flag)
                        return false;
                }
                else
                {
                    flag = true;
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                    if (flag)
                        return false;
                }
                else
                {
                    flag = true;
                }
            }
        }
        return true;
    }
};