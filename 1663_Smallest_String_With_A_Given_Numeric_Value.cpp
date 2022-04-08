#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string res(n, 'a');
        int q = (k - n) / 25;
        for (int i = 0; i < q; ++i)
            res[n - 1 - i] += 25;
        if (n - q > 0)
            res[n - q - 1] += (k - n) % 25;
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 9, k = 34;

    cout << s.getSmallestString(n, k) << endl;

    return 0;
}