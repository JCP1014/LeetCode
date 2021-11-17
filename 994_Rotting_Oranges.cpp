#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int minutes = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    ++fresh;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if (!fresh)
            return 0;
        if (fresh && q.empty())
            return -1;
        q.push({-1, -1});
        while (q.size() > 1 && fresh)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == -1)
            {
                ++minutes;
                q.push({-1, -1});
            }
            else
            {
                if (r + 1 < m && grid[r + 1][c] == 1)
                {
                    q.push({r + 1, c});
                    grid[r + 1][c] = 2;
                    --fresh;
                }
                if (c + 1 < n && grid[r][c + 1] == 1)
                {
                    q.push({r, c + 1});
                    grid[r][c + 1] = 2;
                    --fresh;
                }
                if (r - 1 >= 0 && grid[r - 1][c] == 1)
                {
                    q.push({r - 1, c});
                    grid[r - 1][c] = 2;
                    --fresh;
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1)
                {
                    q.push({r, c - 1});
                    grid[r][c - 1] = 2;
                    --fresh;
                }
            }
        }
        return (fresh) ? -1 : (++minutes);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << s.orangesRotting(grid) << endl;

    return 0;
}