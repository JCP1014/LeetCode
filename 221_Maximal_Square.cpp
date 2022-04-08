#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int res = 0;

        for (int i = 0; i < r; ++i)
        {
            dp[i][0] = (matrix[i][0] - '0');
            res = res || dp[i][0];
        }
        for (int j = 0; j < c; ++j)
        {
            dp[0][j] = (matrix[0][j] - '0');
            res = res || dp[0][j];
        }

        for (int i = 1; i < r; ++i)
        {
            for (int j = 1; j < c; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
    Solution s;

    cout << s.maximalSquare(matrix) << endl;

    return 0;
}