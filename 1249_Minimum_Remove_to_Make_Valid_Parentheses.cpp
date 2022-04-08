#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int left = 0;
        string res = "";
        int i;

        for (i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                ++left;
                res += s[i];
            }
            else if (s[i] == ')')
            {
                if (left)
                {
                    --left;
                    res += s[i];
                }
            }
            else
                res += s[i];
        }
        i = res.size() - 1;
        while (left)
        {
            if (res[i] == '(')
            {
                res.erase(i, 1);
                if (--left == 0)
                    break;
            }
            --i;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "))((";

    cout << sol.minRemoveToMakeValid(s) << endl;

    return 0;
}