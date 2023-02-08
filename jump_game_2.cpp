class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int current = 0;
        int first = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            first = max(first, nums[i] + i);

            if (i == current)
            {
                current = first;
                ans++;
            }
        }
        return ans;
    }
};