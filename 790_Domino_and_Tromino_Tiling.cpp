#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilings(int n)
    {
        if (n < 3)
            return n;
        long D[n + 1];
        long P[n + 1];
        int mod = pow(10, 9) + 7;
        D[0] = 0;
        D[1] = 1;
        D[2] = 2;
        P[0] = 0;
        P[1] = 1;
        P[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            D[i] = (D[i - 1] + D[i - 2] + 2 * P[i - 2]) % mod;
            P[i] = (P[i - 1] + D[i - 1]) % mod;
        }
        return D[n];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 5;
    cout << s.numTilings(n) << endl;

    return 0;
}