#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (stk.empty())
                return false;
            else if ((c == ')' && stk.top() == '(') ||
                     (c == ']' && stk.top() == '[') ||
                     (c == '}' && stk.top() == '{'))
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "(]";

    cout << sol.isValid(s) << endl;

    return 0;
}