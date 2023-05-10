class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int x = 1;
        while (x <= n * n)
        {
            for (int i = left; i <= right; i++)
                res[top][i] = x++;
            top++;
            for (int i = top; i <= bottom; i++)
                res[i][right] = x++;
            right--;
            for (int i = right; i >= left; i--)
                res[bottom][i] = x++;
            bottom--;
            for (int i = bottom; i >= top; i--)
                res[i][left] = x++;
            left++;
        }
        return res;
    }
};