class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;

        int x = needle.size();
        int y = haystack.size();

        for (int i = 0; i <= y - x; i++)
        {
            string s = haystack.substr(i, x);
            if (s == needle)
                return i;
        }
        return -1;
    }
};