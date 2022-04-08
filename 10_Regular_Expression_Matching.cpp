#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        /********** Approach 1: Recursion **********
        if (p.empty())
            return s.empty();
        if(s.empty())
            return (p[1] == '*') && (isMatch(s, p.substr(2)));
        if (p[1] != '*')
            return ((s[0] == p[0]) || (p[0] == '.')) && 
                        (isMatch(s.substr(1), p.substr(1)));
        else
            return (isMatch(s, p.substr(2))) || 
                    ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        *******************************************/

        /********** Approach 2: Dynamic Programming (Faster and Less Space) **********/
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1];

        // Initial cases
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = false;
        dp[0][1] = false;
        for (int j = 2; j <= n; ++j)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
            
        // Fill the table
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    dp[i][j] = dp[i][j - 2] || 
                                (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j-2] == '.'));
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    string str = argv[1];
    string p = argv[2];
    cout << s.isMatch(str, p) << endl;

    return 0;
}