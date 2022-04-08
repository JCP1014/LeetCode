#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
            return n;
        vector<int> f(n+1);
        f[1] = 1;
        f[2] = 2;
        for(int i=3; i<=n; ++i)
        {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 3;
    cout << s.climbStairs(n) << endl;

    return 0;
}