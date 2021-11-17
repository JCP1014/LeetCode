#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long l = 1, r = n;
        long long num;
        while (l <= r)
        {
            num = (l + r) / 2;
            int res = guess(num);
            if (res == -1)
            {
                r = num - 1;
            }
            else if (res == 1)
            {
                l = num + 1;
            }
            else
                return num;
        }
        return num;
    }

    int guess(int num)
    {
        if (pick < num)
            return -1;
        if (pick > num)
            return 1;
        return 0;
    }

private:
    const int pick = 2;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 2;
    cout << s.guessNumber(n) << endl;

    return 0;
}