class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            int prevStart = prev[0];
            int prevEnd = prev[1];

            if (currStart > prevEnd)
            {
                cnt++;
                prev = points[i];
            }
            else
            {
                prev[0] = max(prevStart, currStart);
                prev[1] = min(prevEnd, currEnd);
            }
        }
        return cnt;
    }
};