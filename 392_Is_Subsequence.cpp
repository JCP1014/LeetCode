#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        /********** Apprach 1: Two Pointers **********/
        int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j++])
                ++i;
        }
        return i == s.size();

        /********** Apprach 2: Dynamic Programming (LCS) **********
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); ++i)
            for (int j = 1; j <= t.size(); ++j)
                dp[i][j] = (s[i - 1] == t[j - 1]) ? (dp[i - 1][j - 1] + 1) : max(dp[i - 1][j], dp[i][j - 1]);
        return dp[s.size()][t.size()] == s.size();
        ***********************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "axc", t = "ahbgdc";

    cout << sol.isSubsequence(s, t) << endl;

    return 0;
}