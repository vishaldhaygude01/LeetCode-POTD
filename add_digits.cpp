class Solution
{
public:
    int digit(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }
    int addDigits(int num)
    {
        while (num > 9)
        {
            num = digit(num);
        }
        return num;
    }
};