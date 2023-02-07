class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> mp;

        int maxi = 0;
        int i = 0;
        int j = 0;
        int n = fruits.size();

        while (i < n)
        {
            mp[fruits[i]]++;
            i++;
            while (mp.size() > 2)
            {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0)
                    mp.erase(fruits[j]);
                j++;
            }
            maxi = max(maxi, i - j);
        }

        return maxi;
    }
};