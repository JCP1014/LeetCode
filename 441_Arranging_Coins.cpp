#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        /********** Approach 1: O(N ^ 1/2) **********
        int row = 1;
        while(n >= row)
            n -= row++;
        return --row;
        *********************************************/

        /********** Approach 2: O(log N) *************/
        int l = 0, r = n;
        long m, sum, remain;
        while (true)
        {
            m = (l + r) / 2;
            sum = (1 + m) * m / 2;
            remain = n - sum;
            if (remain < 0)
                r = m - 1;
            else if (remain < m + 1)
                return m;
            else if (remain == m + 1)
                return m + 1;
            else if (remain > m + 1)
                l = m + 1;
        }
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 5;
    cout << s.arrangeCoins(n) << endl;

    return 0;
}