class Solution
{
public:
    int ans = 1;
    int rem[100005];
    void dfs(int src, vector<vector<int>> &v, string &s)
    {
        rem[src] = 1;
        for (auto cur : v[src])
        {
            dfs(cur, v, s);
            if (s[cur] != s[src])
            {
                ans = max(ans, rem[src] + rem[cur]);
                rem[src] = max(rem[src], rem[cur] + 1);
            }
        }
    }
    int longestPath(vector<int> &parent, string s)
    {
        vector<vector<int>> adj(parent.size());
        for (int i = 1; i < parent.size(); i++)
            adj[parent[i]].push_back(i);
        dfs(0, adj, s);
        return ans;
    }
};