#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() <= k)
            return "0";
        string stk = "";
        for (char c : num)
        {
            while (stk.size() && k && c < stk.back())
            {
                stk.pop_back();
                --k;
            }
            if (c != '0' || stk.size())
                stk.push_back(c);
        }
        while (stk.size() && k--)
            stk.pop_back();

        return stk.size() ? stk : "0";
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string num = "10001";
    int k = 4;

    cout << s.removeKdigits(num, k) << endl;

    return 0;
}
