#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int start_i, start_j;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                    ++empty;
                else if (grid[i][j] == 1)
                {
                    start_i = i;
                    start_j = j;
                }
            }
        }
        dfs(grid, start_i, start_j, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &grid, int i, int j, int step)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2)
        {
            if (step == empty + 1)
                ++ans;
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i - 1, j, step + 1);
        dfs(grid, i + 1, j, step + 1);
        dfs(grid, i, j - 1, step + 1);
        dfs(grid, i, j + 1, step + 1);
        grid[i][j] = 0;
    }

private:
    int empty = 0;
    int ans = 0;
    int m, n;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << s.uniquePathsIII(grid) << endl;

    return 0;
}