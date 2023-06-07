class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};