#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, 0);
        for (int i = 1; i <= int(sqrt(n)); ++i)
            dp[i * i] = true;

        int root = 2;
        for (int i = 2; i <= n; ++i)
        {
            if (dp[i])
                ++root;
            else
            {
                for (int j = root - 1; j > 0; --j)
                {
                    if (!dp[i - j * j])
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = atoi(argv[1]);

    cout << s.winnerSquareGame(n) << endl;

    return 0;
}