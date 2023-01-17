class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int first = 0;
        int last = 0;
        for (auto i : s)
        {
            if (i == '1')
                first++;
            else
                last++;
            if (first < last)
                last = first;
        }
        return last;
    }
};