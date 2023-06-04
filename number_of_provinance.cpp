class Solution
{
public:
    int n;
    void bfs(vector<vector<int>> &isConnected, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && isConnected[u][v] == 1)
                {
                    bfs(isConnected, v, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        n = isConnected.size();

        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(isConnected, i, visited);
                cnt++;
            }
        }
        return cnt;
    }
};

/*

        //DFS
    int n;
    void dfs(int u, vector<vector<int>>&isConnected, vector<bool>&visited){
        visited[u] = true;

        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v] == 1){
                dfs(v,isConnected,visited);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();
        vector<bool>visited(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }

*/