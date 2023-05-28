class Solution
{
public:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;

        for (int idx = i; idx <= j; idx++)
        {
            int ans = cuts[j + 1] - cuts[i - 1] + f(i, idx - 1, cuts, dp) + f(idx + 1, j, cuts, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return f(1, c, cuts, dp);
    }
};

/*
    //  RECURSION
    int f(int i, int j, vector<int>&cuts){
        if(i > j) return 0;
        int mini = INT_MAX;

        for(int idx=i;idx<=j;idx++){
            int ans = cuts[j+1] - cuts[i-1] + f(i,idx-1,cuts) + f(idx+1,j,cuts);
            mini = min(mini,ans);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts);
    }


    //MEMOIZATION
    int f(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;


        for(int idx=i;idx<=j;idx++){
            int ans = cuts[j+1] - cuts[i-1] + f(i,idx-1,cuts,dp) + f(idx+1,j,cuts,dp);
            mini = min(mini,ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return f(1,c,cuts,dp);
    }

*/