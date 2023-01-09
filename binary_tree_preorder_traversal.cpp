class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> list;
        if (root == NULL)
        {
            return list;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            list.push_back(root->val);
            if (root->right != NULL)
            {
                st.push(root->right);
            }
            if (root->left != NULL)
            {
                st.push(root->left);
            }
        }
        return list;
    }
};
/*
void printPreorder(TreeNode* root,vector<int>&res){
        if(root==NULL)return;
        res.push_back(root->val);
        printPreorder(root->left,res);
        printPreorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        printPreorder(root,res);
        return res;
    }
*/