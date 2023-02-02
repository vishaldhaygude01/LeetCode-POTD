class Solution
{
public:
    bool compare(string &s, string &t, string &order)
    {
        int i = 0;
        while (i < s.size() && s[i] == t[i])
        {
            i++;
        }
        if (s.size() == i)
            return true;
        else if (t.size() == i)
            return false;
        return (order.find(s[i]) < order.find(t[i]));
    }
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!compare(words[i], words[i + 1], order))
                return false;
        }
        return true;
    }
};