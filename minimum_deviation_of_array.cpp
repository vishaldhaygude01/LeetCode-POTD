class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int minNum = INT_MAX;
        int Diff = INT_MAX;
        for (auto i : nums)
        {
            if (i % 2 != 0)
            {
                i = i * 2;
            }
            minNum = min(minNum, i);
            pq.push(i);
        }
        while (pq.top() % 2 == 0)
        {
            int maxNum = pq.top();
            pq.pop();
            Diff = min(Diff, maxNum - minNum);
            minNum = min(minNum, maxNum / 2);
            pq.push(maxNum / 2);
        }
        return min(Diff, pq.top() - minNum);
    }
};