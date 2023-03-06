class Solution
{
public:
    int findKthPositive(vector<int> &nums, int k)
    {
        int num = 1;
        int n = nums.size();
        int i = 0;

        while (i < n && k > 0)
        {
            if (nums[i] == num)
            {
                i++;
            }
            else
            {
                k--;
            }
            num++;
        }
        while (k--)
        {
            num++;
        }
        return num - 1;
    }
};