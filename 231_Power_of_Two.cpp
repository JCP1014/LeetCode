#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        /********** Approach 1 (Mine) **********
        if(n <= 0)
            return false;
        bool hasOne = false;
        while (n)
        {
            if (n & 1)
            {
                if (hasOne)
                    return false;
                hasOne = true;
            }
            n >>= 1;
        }
        return true;
        ****************************************/

        /*********** Approach 2 ****************/
        return (n > 0) && !(n & (n - 1));

        /*********** Approach 3 ****************
        if(n <= 0)
            return false;
        bitset<32> b(n);
        return b.count() == 1;
        ****************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 16;

    cout << s.isPowerOfTwo(n) << endl;

    return 0;
}