class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;
        int maxSum = 0;
        int minSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxSum += nums[i];
            maxi = max(maxi, maxSum);
            maxSum = max(maxSum, 0);

            minSum += nums[i];
            mini = min(mini, minSum);
            minSum = min(minSum, 0);

            sum += nums[i];
        }

        return maxi < 0 ? maxi : max(maxi, sum - mini);
    }
};