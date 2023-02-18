class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *current = st.top();
            st.pop();
            swap(current->left, current->right);
            if (current->left)
            {
                st.push(current->left);
            }
            if (current->right)
            {
                st.push(current->right);
            }
        }
        return root;
    }
};
// invertTree(root->left);
// invertTree(root->right);
// swap(root->left,root->right);
// return root;