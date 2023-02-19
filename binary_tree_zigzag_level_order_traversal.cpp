
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int idx = (flag) ? i : (size - 1 - i);

                row[idx] = node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};