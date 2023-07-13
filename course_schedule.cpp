class Solution
{
public:
    // DFS
    bool isCycle(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v] && isCycle(adj, v, visited, inRecursion))
            {
                return true;
            }
            else if (inRecursion[v] == true)
            {
                return true;
            }
        }
        inRecursion[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && isCycle(adj, i, visited, inRecursion))
            {
                return false;
            }
        }

        return true;
    }
};

/*

// BFS
        // KHAN'S ALGORITHAM
    bool topologicalSort(unordered_map<int, vector<int>>&adj, int n, vector<int>& indegree){
        queue<int>q;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                cnt++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int& v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    cnt++;
                    q.push(v);
                }
            }

        }
        if(cnt == n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj,numCourses,indegree);
    }





*/