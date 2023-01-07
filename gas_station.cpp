class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int sumGas = accumulate(gas.begin(), gas.end(), 0);
        int sumCost = accumulate(cost.begin(), cost.end(), 0);

        if (sumGas < sumCost)
            return -1;

        int total = 0;
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            if (total < 0)
            {
                total = 0;
                result = i + 1;
            }
        }
        return result;
    }
};