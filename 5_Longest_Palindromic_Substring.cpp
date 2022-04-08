#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /*************** (Worse) Approach 1: Dynamic Programming ***************/
        /***********************************************************************
        int n = s.size();
        bool P[n][n];
        int maxLen = 0;
        string ans = "";
        // P(i, j) = true, if the substring Si...Sj is a palindrome
        // P(i, j) = false, otherwise
        // P(i, j) = ( P(i+1, j-1) && Si==Sj )
        // Base cases:
        // P(i, i) = true
        // P(i, i+1) = (S[i]==S[i+1])
        for (int i = 0; i < n - 1; ++i)
        {
            P[i][i] = true;
            P[i][i + 1] = (s[i] == s[i + 1]);
        }
        P[n - 1][n - 1] = true;
        for (int i = n - 3; i >= 0; --i)
        {
            for (int j = i + 2; j < n; ++j)
                P[i][j] = (P[i + 1][j - 1] && s[i] == s[j]);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (P[i][j])
                {
                    if (j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                    break;
                }
            }
        }
        ***********************************************************************/


        /*************** (Better) Approach 2: Expand Around Center ***************/
        int n = s.size();
        string ans = s.substr(0, 1);
        int maxLen = 1;
        int center = 0;
        int l, r;
        while (center < n)
        {
            l = center;
            r = center;
            while (s[r + 1] == s[r]) // Skip duplicate characters.
                ++r;
            center = r + 1;
            while ((l > 0) && (r < n - 1) && (s[l - 1] == s[r + 1]))
            {
                --l;
                ++r;
            }
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                ans = s.substr(l, maxLen);
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;

    return 0;
}
