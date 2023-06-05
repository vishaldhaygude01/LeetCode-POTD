class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int points = coordinates.size();
        int xdiff = abs(coordinates[1][0] - coordinates[0][0]);
        int ydiff = abs(coordinates[1][1] - coordinates[0][1]);
        int curr_xdiff;
        int curr_ydiff;

        for (int i = 2; i < points; ++i)
        {
            curr_xdiff = abs(coordinates[i][0] - coordinates[i - 1][0]);
            curr_ydiff = abs(coordinates[i][1] - coordinates[i - 1][1]);
            if (ydiff * curr_xdiff != xdiff * curr_ydiff)
                return false;
        }
        return true;
    }
};