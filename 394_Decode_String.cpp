#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> stk;
        string res = "";
        for (auto c : s)
        {
            if (c != ']')
                stk.push(c);
            else
            {
                string tmp = "";
                while (stk.top() != '[')
                {
                    tmp += stk.top();
                    stk.pop();
                }
                stk.pop();

                int times = 0;
                int pos = 1;
                while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9')
                {
                    times += (stk.top() - '0') * pos;
                    stk.pop();
                    pos *= 10;
                }

                reverse(tmp.begin(), tmp.end());
                for (int i = 0; i < times; ++i)
                    for (auto ch : tmp)
                        stk.push(ch);
            }
        }
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = "100[leetcode]";

    cout << s.decodeString(str) << endl;

    return 0;
}
