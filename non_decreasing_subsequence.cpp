class Solution
{
public:
    map<vector<int>, int> m;
    void util(int index, vector<int> &nums, vector<int> &sb, vector<vector<int>> &ans)
    {
        vector<int> check = sb;
        sort(check.begin(), check.end());
        if (check == sb and sb.size() >= 2 and m.find(sb) == m.end())
        {
            ans.push_back(sb);
            m[sb] = 1;
        }
        for (int i = index; i < nums.size(); i++)
        {
            sb.push_back(nums[i]);
            util(i + 1, nums, sb, ans);
            sb.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> sb;
        vector<vector<int>> ans;
        util(0, nums, sb, ans);
        return ans;
    }
};