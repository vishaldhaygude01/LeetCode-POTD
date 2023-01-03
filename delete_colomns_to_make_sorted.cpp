class Solution
{
public:
    int minDeletionSize(vector<string> &s)
    {
        int n = s.size();
        int k = s[0].size();

        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (s[j][i] < s[j - 1][i])
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};