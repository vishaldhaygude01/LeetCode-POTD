class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
        {
            return {};
        }
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        vector<int> ans;
        for (int i = 0; i < p.size(); i++)
        {
            hash1[p[i] - 'a']++;
            hash2[s[i] - 'a']++;
        }
        if (hash1 == hash2)
        {
            ans.push_back(0);
        }
        for (int i = p.size(); i < s.size(); i++)
        {
            hash2[s[i] - 'a']++;
            hash2[s[i - p.size()] - 'a']--;
            if (hash1 == hash2)
            {
                ans.push_back(i + 1 - p.size());
            }
        }
        return ans;
    }
};