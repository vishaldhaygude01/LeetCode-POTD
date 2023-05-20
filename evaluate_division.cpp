class Solution
{
public:
    double dfs(string src, string dst, unordered_set<string> &visited)
    {
        if (graph.find(src) == graph.end())
            return -1;
        if (src == dst)
            return 1;

        for (auto node : graph[src])
        {
            if (visited.count(node.first))
                continue;
            visited.insert(node.first);
            double res = dfs(node.first, dst, visited);
            if (res != -1)
                return res * node.second;
        }
        return -1;
    }
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, (double)1 / val});
        }

        vector<double> result;
        for (auto query : queries)
        {
            unordered_set<string> visited;
            result.push_back(dfs(query[0], query[1], visited));
        }
        return result;
    }
};