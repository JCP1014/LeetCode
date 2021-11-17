#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = (text1[i - 1] == text2[j - 1]) ? (dp[i - 1][j - 1] + 1) : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string text1 = "abc", text2 = "def";
    cout << s.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}