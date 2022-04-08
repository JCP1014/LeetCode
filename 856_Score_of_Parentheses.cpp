#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        /********** Approach 1: O(N) Space **********
        stack<int> stk;
        int sum;
        for (auto c : s)
        {
            if (c == '(')
                stk.push(0);
            else
            {
                sum = 0;
                if (stk.top() == 0)
                    sum = 1;
                else
                {
                    while (stk.top() > 0)
                    {
                        sum += stk.top();
                        stk.pop();
                    }
                    sum *= 2;
                }
                stk.pop();
                stk.push(sum);
            }
        }
        sum = 0;
        while(!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }
        return sum;
        *********************************************/

        /********** Approach 2: O(1) Space **********/
        int layer = 0;
        int res = 0;
        for (int i=0; i<s.size(); ++i)
        {
            layer = (s[i] == '(') ? layer + 1 : layer - 1;
            if (s[i] == ')' && s[i-1] == '(')
                res += (1 << layer);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "((()))()";

    cout << sol.scoreOfParentheses(s) << endl;

    return 0;
}