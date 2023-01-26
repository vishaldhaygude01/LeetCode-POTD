class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX >> 1));
        dp[0][src] = dp[1][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (vector<int> &flight : flights)
            {
                int prev_node = flight[0], cur_node = flight[1], cur_dist = flight[2];
                dp[i & 1][cur_node] = min(dp[i & 1][cur_node],
                                          dp[(i - 1) & 1][prev_node] + cur_dist);
            }
        }
        return dp[(k + 1) & 1][dst] == INT_MAX >> 1 ? -1 : dp[(k + 1) & 1][dst];
    }
};