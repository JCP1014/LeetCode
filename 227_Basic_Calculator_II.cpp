#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        /******************** Approach 1: Stack ********************/
        stack<int> stk;
        int currentNumber = 0;
        char op = '+';
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
                currentNumber = currentNumber * 10 + (s[i] - '0');
            if (!isdigit(s[i]) || i == s.size() - 1)
            {
                if (s[i] != ' ' || i == s.size() - 1)
                {
                    if (op == '+')
                        stk.push(currentNumber);
                    else if (op == '-')
                        stk.push(-currentNumber);
                    else if (op == '*')
                    {
                        int val = stk.top() * currentNumber;
                        stk.pop();
                        stk.push(val);
                    }
                    else if (op == '/')
                    {
                        int val = stk.top() / currentNumber;
                        stk.pop();
                        stk.push(val);
                    }
                    op = s[i];
                    currentNumber = 0;
                }
            }
            ++i;
        }
        while (!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;

        /********** Approach 2: One variable instead of stack **********
        int lastNumber = 0;
        int currentNumber = 0;
        char op = '+';
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
                currentNumber = currentNumber * 10 + (s[i] - '0');
            if (!isdigit(s[i]) || i == s.size() - 1)
            {
                if (s[i] != ' ' || i == s.size() - 1)
                {
                    if (op == '+')
                    {
                        res += lastNumber;
                        lastNumber = currentNumber;
                    }
                    else if (op == '-')
                    {
                        res += lastNumber;
                        lastNumber = -currentNumber;
                    }
                    else if (op == '*')
                    {
                        lastNumber *= currentNumber;
                    }
                    else if (op == '/')
                    {
                        lastNumber /= currentNumber;
                    }
                    op = s[i];
                    currentNumber = 0;
                }
            }
            ++i;
        }
        res += lastNumber;
        return res;
        ****************************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = " 3+5 / 2 ";
    cout << s.calculate(str) << endl;

    return 0;
}