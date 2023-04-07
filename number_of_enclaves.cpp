class Solution
{
public:
    void f(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        f(i - 1, j, n, m, grid);
        f(i + 1, j, n, m, grid);
        f(i, j - 1, n, m, grid);
        f(i, j + 1, n, m, grid);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (grid[i][j] == 1))
                {
                    f(i, j, n, m, grid);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};