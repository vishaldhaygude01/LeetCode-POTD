
class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        long long mod = 1e9 + 7;
        vector<long long> dp(200005);
        long long f = 0;

        dp[0] = 1;
        for (int i = 0; i < 100005; i++)
        {
            dp[i + zero] %= mod;
            dp[i + zero] += dp[i];
            dp[i + one] %= mod;
            dp[i + one] += dp[i];
        }
        for (int i = low; i <= high; i++)
            f = (f + dp[i]) % mod;
        return f;
    }
};