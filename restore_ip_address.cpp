class Solution
{
public:
    set<string> res;

    void solve(string s, int idx, string IP, int dots)
    {
        if (dots == 4 and idx == s.size())
        {
            res.insert(IP.substr(0, IP.size() - 1));
            return;
        }

        if (dots > 4)
            return;

        for (int i = idx; i < (min(idx + 3, (int)s.size())); i++)
        {
            string sub = s.substr(idx, i - idx + 1);
            if (stoi(sub) <= 255 and (i == idx or s[idx] != '0'))
            {
                solve(s, i + 1, IP + sub + ".", dots + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        solve(s, 0, "", 0);
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};