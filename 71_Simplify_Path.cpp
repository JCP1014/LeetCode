#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        /********** Approach 1: With stringstream **********/
        stringstream ss(path);
        string tmp;
        stack<string> stk;
        string res = "";

        while (getline(ss, tmp, '/'))
        {
            if (tmp == "..")
            {
                if (!stk.empty())
                    stk.pop();
            }
            else if (!tmp.empty() && tmp != ".")
                stk.push(tmp);
        }
        while (!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;

        /********** Approach 2: Without stringstream **********
        string tmp = "";
        stack<string> stk;
        string res = "";
        int i = 0;

        while (i < path.size())
        {
            while (i < path.size() && path[i] != '/')
                tmp += path[i++];
            if (tmp == "..")
            {
                if (!stk.empty())
                    stk.pop();
            }
            else if (tmp != "." && tmp != "")
                stk.push(tmp);
            tmp = "";
            ++i;
        }

        while (!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;
        *******************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string path = "/a//b////c/d//././/..";

    cout << s.simplifyPath(path) << endl;

    return 0;
}