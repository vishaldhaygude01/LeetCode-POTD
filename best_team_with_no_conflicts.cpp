class Solution
{
public:
    int highestScore(int n, vector<pair<int, int>> &vec)
    {
        int maxScore = 0;
        vector<int> dp(n);

        for (int i = 0; i < n; ++i)
        {
            dp[i] = vec[i].second;
            for (int j = i - 1; j >= 0; --j)
            {
                if (vec[i].second >= vec[j].second)
                    dp[i] = max(dp[i], dp[j] + vec[i].second);
            }
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();

        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i)
        {
            vec[i] = {ages[i], scores[i]};
        }
        sort(vec.begin(), vec.end());
        return highestScore(n, vec);
    }
};