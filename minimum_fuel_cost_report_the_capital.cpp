class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&adjList, int node, int prev, int seats, long long&fuel) {
        int rep = 1;
        
        for (int adjNode : adjList[node]) {
            if (adjNode == prev) continue;
            rep += dfs(adjList, adjNode, node, seats, fuel);
        }
        
        if (node != 0) fuel += (rep / seats) + (rep % seats > 0);
        return rep;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
         unordered_map<int, vector<int>> adjList;
        long long fuel = 0;
        
        for (vector<int> road : roads) {
            int src = road[0];
            int dest = road[1];
            
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        dfs(adjList, 0, 0, seats, fuel);
        return fuel;
    }
};