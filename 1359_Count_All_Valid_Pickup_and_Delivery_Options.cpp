#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOrders(int n)
    {
        long res = 1;
        int pos;
        int mod = pow(10, 9) + 7;
        for (int i = 2; i <= n; ++i)
        {
            pos = ((i - 1) * 2 + 1);
            res *= ((1 + pos) * pos / 2);
            res %= mod;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 2;
    cout << s.countOrders(n) << endl;

    return 0;
}