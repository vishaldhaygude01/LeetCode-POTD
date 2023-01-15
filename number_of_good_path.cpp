class dsu
{
public:
    vector<int> parent;
    vector<int> rank;
    dsu(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find_parent(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a] = find_parent(parent[a]);
    }
    void join(int a, int b)
    {
        int p1 = find_parent(a);
        int p2 = find_parent(b);
        if (rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else if (rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
};
class Solution
{
public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {

        int n = vals.size();
        int ans = n;
        dsu obj(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[vals[i]].push_back(i);
        vector<int> adj[n];
        for (auto g : edges)
        {
            int u = g[0], w = g[1];
            if (vals[u] >= vals[w])
                adj[u].push_back(w);
            if (vals[w] >= vals[u])
                adj[w].push_back(u);
        }
        for (auto &[lowest_cur_val, nodes] : mp)
        {
            map<int, int> counter;
            for (auto node : nodes)
            {
                for (auto neighbours : adj[node])
                {
                    obj.join(node, neighbours);
                }
            }
            for (auto node : nodes)
            {
                counter[obj.find_parent(node)]++;
            }

            for (auto &[x, frequency] : counter)
            {
                if (frequency > 1)
                {
                    ans += (frequency * (frequency - 1)) / 2;
                }
            }
        }
        return ans;
    }
};