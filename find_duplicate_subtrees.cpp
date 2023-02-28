class Solution
{
public:
    map<string, int> mp;
    string solve(TreeNode *root, vector<TreeNode *> &ans)
    {
        if (!root)
            return "#";
        string s = solve(root->left, ans) + ',' + solve(root->right, ans) + ',' + to_string(root->val);
        mp[s]++;
        if (mp[s] == 2)
            ans.push_back(root);
        return s;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> ans;
        solve(root, ans);
        return ans;
    }
};