class SummaryRanges
{
private:
    set<int> st;

public:
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        st.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> result;
        int s = 0;
        vector<int> temp(st.begin(), st.end());

        int i = 0;
        while (i < temp.size())
        {
            int s = temp[i];

            while (i + 1 < temp.size() && temp[i] + 1 == temp[i + 1])
                i++;
            result.push_back({s, temp[i]});
            i++;
        }
        return result;
    }
};