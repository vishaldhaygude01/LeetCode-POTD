class Solution
{
public:
    int count(string s, int k, char ch)
    {
        int n = s.length();
        int maxlen = 0, bad = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (s[j] != ch)
                bad++;
            while (i <= j && bad > k)
            {
                char cur = s[i];
                if (cur != ch)
                    bad--;
                i++;
            }

            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen;
    }

    int maxConsecutiveAnswers(string s, int k)
    {
        return max(count(s, k, 'T'), count(s, k, 'F'));
    }
};