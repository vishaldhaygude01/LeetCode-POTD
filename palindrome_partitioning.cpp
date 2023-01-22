class Solution
{
public:
    bool isPallindrome(string S, int start, int end)
    {
        while (start <= end)
        {
            if (S[start++] != S[end--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(int index, string S, vector<string> &ds, vector<vector<string>> &res)
    {
        if (index == S.size())
        {
            res.push_back(ds);
            return;
        }
        for (int i = index; i < S.size(); i++)
        {
            if (isPallindrome(S, index, i))
            {
                ds.push_back(S.substr(index, i - index + 1));
                solve(i + 1, S, ds, res);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string S)
    {
        vector<vector<string>> res;
        vector<string> ds;
        solve(0, S, ds, res);
        return res;
    }
};