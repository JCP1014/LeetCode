#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        /********** Approach 1: Less time, More Memory **********
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i)
        {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j])
            {
                stk.pop();
                ++j;
            }
        }
        return stk.empty();
        *********************************************************/

        /********** Approach 2: More time, Less Memory **********
        int i = 0, j = 0;
        while (i < pushed.size())
        {
            while (!pushed.empty() && pushed[i] == popped[j])
            {
                pushed.erase(pushed.begin() + i);
                i = i ? i - 1 : i;
                ++j;
            }
            ++i;
        }
        return pushed.empty();
        *********************************************************/

        /********** Approach 3: Less time, Less Memory **********/
        int i = 0, j = 0;
        for (auto p : pushed)
        {
            pushed[i] = p;
            while (i >= 0 && pushed[i] == popped[j])
            {
                --i;
                ++j;
            }
            ++i;
        }
        return i == 0;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> pushed = {1, 0}, popped = {1, 0};

    cout << s.validateStackSequences(pushed, popped) << endl;

    return 0;
}