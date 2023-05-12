class Solution
{
public:
    long long f(int i, vector<vector<int>> &q, vector<long long> &dp)
    {
        if (i >= q.size())
            return 0;
        long long ans = 0;
        if (dp[i] != -1)
            return dp[i];
        ans = max(q[i][0] + f(i + q[i][1] + 1, q, dp), f(i + 1, q, dp));
        dp[i] = ans;
        return ans;
    }
    long long mostPoints(vector<vector<int>> &q)
    {
        int n = q.size();
        vector<long long> dp(n, -1);
        return f(0, q, dp);
    }
};