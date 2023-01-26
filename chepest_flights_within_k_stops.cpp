class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dist, int k)
    {
        vector<int> distance(n, INT_MAX);

        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int> &vec : flights)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v, cost});
        }

        // BFS
        queue<pair<int, int>> q;
        q.push({src, 0});
        distance[src] = 0;

        int steps = 0;
        while (!q.empty() && steps <= k)
        {
            int size = q.size();
            while (size--)
            {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                for (pair<int, int> &p : adj[u])
                {
                    int v = p.first;
                    int cost = p.second;

                    if (distance[v] > d + cost)
                    {
                        distance[v] = d + cost;
                        q.push({v, d + cost});
                    }
                }
            }
            steps++;
        }
        if (distance[dist] == INT_MAX)
            return -1;
        return distance[dist];
    }
};