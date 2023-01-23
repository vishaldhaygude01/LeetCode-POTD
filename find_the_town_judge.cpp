class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> cnt(n + 1);

        for (vector<int> &vec : trust)
        {
            int u = vec[0];
            int v = vec[1];

            cnt[u]--;
            cnt[v]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == n - 1)
                return i;
        }
        return -1;
    }
};

/*

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n+1);
        vector<int>outDegree(n+1);

        for(vector<int>&vec : trust){
            int u = vec[0];
            int v = vec[1];

            outDegree[u]++;
            inDegree[v]++;
        }

        for(int i=1;i<=n;i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0) return i;
        }

        return -1;
    }
};

*/