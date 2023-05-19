class Solution
{
public:
    bool bfs(vector<vector<int>> &graph, int u, vector<int> &color, int v)
    {
        queue<int> q;
        q.push(u);
        color[u] = v;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int &a : graph[curr])
            {
                if (color[a] == color[curr])
                    return false;
                else if (color[a] == -1)
                {
                    color[a] = 1 - color[curr];
                    q.push(a);
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(graph, i, color, 1) == false)
                    return false;
            }
        }
        return true;
    }
};

/*
    //DFS

     bool dfs(int u, vector<vector<int>>& graph, vector<int>&color){
        for(auto v: graph[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                if(!dfs(v,graph,color)) return false;
            }
            else if(color[v] == color[u]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 1;
                if(dfs(i,graph,color) == false) return false;
            }
        }
        return true;
    }

*/