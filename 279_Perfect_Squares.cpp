#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        static vector<int> dp{0};
        for (int i = dp.size(); i <= n; ++i)
        {
            int res = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
            {
                res = min(res, dp[i - j * j] + 1);
            }
            dp.push_back(res);
        }
        return dp[n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 13;
    cout << s.numSquares(n) << endl;

    return 0;
}