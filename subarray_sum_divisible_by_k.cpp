class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int sum = 0;
        int ans = 0;
        vector<int> a(k);
        a[0] = 1;

        int rem;
        for (int num : nums)
        {
            sum += num;
            rem = (sum % k + k) % k;
            ans += a[rem];
            a[rem]++;
        }
        return ans;
    }
};