#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    // if (i == 0 || grid[i - 1][j] == 0)   ++ans;
                    ans += (i == 0 || grid[i - 1][j] == 0) ? 1 : 0;

                    // if (i == grid.size() - 1 || grid[i + 1][j] == 0) ++ans;
                    ans += (i == grid.size() - 1 || grid[i + 1][j] == 0) ? 1 : 0;

                    // if (j == 0 || grid[i][j - 1] == 0)   ++ans;
                    ans += (j == 0 || grid[i][j - 1] == 0) ? 1 : 0;

                    // if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)  ++ans;
                    ans += (j == grid[0].size() - 1 || grid[i][j + 1] == 0) ? 1 : 0;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    cout << s.islandPerimeter(grid) << endl;

    return 0;
}