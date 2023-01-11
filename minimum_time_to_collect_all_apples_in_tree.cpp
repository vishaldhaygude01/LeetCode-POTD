class Solution
{
public:
    int f(int node, vector<vector<int>> &graph, vector<bool> &hasApple, vector<bool> &visited)
    {
        int cnt = 0;
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int child = graph[node][i];
            if (visited[child])
                continue;
            cnt += f(child, graph, hasApple, visited);
            if (hasApple[child])
                cnt += 2;
        }
        if (cnt)
            hasApple[node] = true;
        return cnt;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return f(0, graph, hasApple, visited);
    }
};