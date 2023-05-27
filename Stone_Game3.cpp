class Solution
{
public:
    string stoneGameIII(vector<int> &ans)
    {
        int n = ans.size();
        vector<int> dp(n + 3, 0);

        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);

        int temp;
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = ans[i] - dp[i + 1];
            dp[i] = max(dp[i], ans[i + 1] + ans[i] - dp[i + 2]);
            dp[i] = max(dp[i], ans[i + 1] + ans[i] + ans[i + 2] - dp[i + 3]);
        }

        if (dp[0] == 0)
            return "Tie";
        if (dp[0] > 0)
            return "Alice";
        return "Bob";
    }
};