#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        /*************** Approach 1 ***************
        vector<int> res(n + 1, 0);
        int start = 1, next_start = 2;
        for (int i = 1; i <= n; ++i)
        {
            if (i == next_start)
            {
                start = next_start;
                next_start <<= 1;
            }
            res[i] = res[i - start] + 1;
        }
        return res;
        *******************************************/

        /*************** Approach 2 ***************/
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            res[i] = res[i >> 1] + (i & 1);
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 2;
    vector<int> res = s.countBits(n);
    for (auto r : res)
        cout << r << endl;

    return 0;
}