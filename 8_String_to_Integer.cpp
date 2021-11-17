#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    int myAtoi(string s)
    {
        bool negative = false;
        long ans = 0;
        int index = 0;

        while (s[index] == ' ')
            ++index;
        if (s[index] == '-')
        {
            negative = true;
            ++index;
        }
        else if (s[index] == '+')
        {
            ++index;
        }
        for (int i=index; i<s.size(); ++i)
        {
            if (s[i] < '0' || s[i] > '9')
                break;
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX)
                return (negative ? INT_MIN : INT_MAX);
        }

        return (negative ? -ans : ans);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    string str = "20000000000000000000";
    cout << s.myAtoi(str) << endl;

    return 0;
}