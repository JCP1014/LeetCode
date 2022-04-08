#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        /****************** Approach 1 (Mine) ******************
        int res = 0;
        int exp = 0;
        while(num)
        {
            res = ((num ^ 1) & 1) ? res + pow(2, exp) : res;
            num >>= 1;
            ++exp;
        }
        return res;
        ********************************************************/

        /****************** Approach 2 ******************
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask ^ num;
        *************************************************/

        /****************** Approach 3 ******************/
        int res = num;
        int i = 0;
        while (num)
        {
            res ^= (1 << i++);
            num >>= 1;
        }
        return res;

        /****************** Approach 4 ******************
        bitset<32> b(num);
        int pos = 31;
        while (!b[pos])
            --pos;
        while(pos >= 0)
            b.flip(pos--);
        return b.to_ulong();
        *************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int num = 5;
    cout << s.findComplement(num) << endl;

    return 0;
}