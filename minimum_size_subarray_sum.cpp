class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int sum = 0;
        int minsize = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                minsize = min(minsize, i - start + 1);
                sum -= nums[start++];
            }
        }
        if (minsize == INT_MAX)
            return 0;
        return minsize;
    }
};