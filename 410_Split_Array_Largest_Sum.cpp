#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        vector<int> sums(n, nums[0]);
        vector<vector<int>> dp(n, vector<int>(m + 1, INT_MAX));

        for (int i = 1; i < n; ++i)
            sums[i] = sums[i - 1] + nums[i];
        for (int i = 0; i < n; ++i)
            dp[i][1] = sums[i];
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sums[i] - sums[k]));
                }
            }
        }
        return dp[n - 1][m];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;

    cout << s.splitArray(nums, m) << endl;

    return 0;
}