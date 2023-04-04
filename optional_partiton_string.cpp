class Solution
{
public:
    int partitionString(string s)
    {
        set<char> st;
        int cnt = 0;
        for (auto it : s)
        {
            if (st.find(it) != st.end())
            {
                cnt++;
                st.clear();
                st.insert(it);
            }
            else
                st.insert(it);
        }
        return cnt + 1;
    }
};