#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
                return helper(s, l + 1, r) || helper(s, l, r - 1);
        }
        return true;
    }
    bool helper(string s, int l, int r)
    {
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "abc";

    cout << sol.validPalindrome(s) << endl;

    return 0;
}