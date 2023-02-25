class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        int minipri = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            minipri = min(minipri, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minipri);
        }
        return maxprofit;
    }
};
