class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int n1, int n2)
    {
        if (n1 == n2)
            return n1;
        int n = size(edges);
        vector<int> vis(n);
        while (n-- && (n1 != -1 || n2 != -1))
        {
            int ans = -1;
            if (n1 != -1)
            {
                if (vis[n1] == 2)
                    ans = n1;
                vis[n1] = 1;
                n1 = edges[n1];
            }
            if (n2 != -1)
            {
                if (vis[n2] == 1)
                {
                    if (ans == -1 or n2 < ans)
                        ans = n2;
                };
                vis[n2] = 2;
                n2 = edges[n2];
            }
            if (ans != -1)
                return ans;
        }
        return -1;
    }
};