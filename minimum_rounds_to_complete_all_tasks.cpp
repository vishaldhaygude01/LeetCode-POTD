class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (int it : tasks)
        {
            mp[it]++;
        }
        int numR = 0;
        for (const auto &[difficulty, count] : mp)
        {
            if (count < 2)
                return -1;
            int rounds = (count + 2) / 3;
            numR += rounds;
        }
        return numR;
    }
};
