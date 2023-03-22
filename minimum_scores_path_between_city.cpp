class Solution
{
public:
    int minScore(int size, vector<vector<int>> &adj)
    {

        vector<int> v(size + 2, 0);
        int f = INT_MAX;
        vector<vector<pair<int, int>>> path(size + 1);
        queue<vector<int>> que;
        que.push({size, INT_MAX});

        for (int a = 0; a < adj.size(); a++)
        {
            path[adj[a][0]].push_back({adj[a][1], adj[a][2]});
            path[adj[a][1]].push_back({adj[a][0], adj[a][2]});
        }

        while (!que.empty())
        {
            auto curr = que.front();
            que.pop();
            f = min(f, curr[1]);
            v[curr[0]] = 1;
            for (auto g : path[curr[0]])
            {
                if (!v[g.first])
                    que.push({g.first, g.second});
            }
        }
        return f;
    }
};