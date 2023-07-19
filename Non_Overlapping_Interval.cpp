class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals));
        int n = intervals.size();

        int count = 0;
        int i = 0, j = 1;

        while (j < n)
        {
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int curr_start = curr_interval[0];
            int curr_end = curr_interval[1];

            int next_start = next_interval[0];
            int next_end = next_interval[1];

            if (curr_end <= next_start)
            { // SAFE
                i = j;
                j++;
            }
            else if (curr_end <= next_end)
            {
                /*
                    GREEDY : Remove next interval as it has high chances to
                             overlap with future intervals
                */
                j++;
                count++;
            }
            else if (curr_end > next_end)
            {
                /*
                    GREEDY : Remove current interval as it has high chances to
                             overlap with future intervals
                */
                i = j;
                j++;
                count++;
            }
        }

        return count;
    }
};