class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> v(obstacles.size(), (int)1e9), ans;
        for (int it : obstacles)
        {
            auto ub = upper_bound(begin(v), end(v), it);
            ans.emplace_back(ub - v.begin() + 1);
            *ub = it;
        }
        return ans;
    }
};