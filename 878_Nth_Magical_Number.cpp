#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        long LCM = lcm(a, b);
        long l = min(a, b), r = l * n;
        long m, num;
        while (l < r)
        {
            m = (l + r) / 2;
            num = m / a + m / b - m / LCM;
            if (num < n)
                l = m + 1;
            else
                r = m;
        }
        return l % long(pow(10, 9) + 7);
    }
    long lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 3, a = 6, b = 4;

    cout << s.nthMagicalNumber(n, a, b) << endl;

    return 0;
}