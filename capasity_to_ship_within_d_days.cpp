class Solution
{
public:
    bool isFeasible(vector<int> &weights, int days, int capacity)
    {
        int sum = 0;
        int day = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + sum <= capacity)
                sum += weights[i];
            else
            {
                sum = 0;
                sum += weights[i];
                day++;
            }
        }
        if (sum > 0)
            day++;
        return day <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxWeight = -1;
        int totalWeight = 0;
        int ans = -1;
        for (int weight : weights)
        {
            maxWeight = max(maxWeight, weight);
            totalWeight = totalWeight + weight;
        }
        int low = maxWeight, high = totalWeight;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isFeasible(weights, days, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};