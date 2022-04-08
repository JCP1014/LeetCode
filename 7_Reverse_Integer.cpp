#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    int reverse(int x)
    {
        if (x > INT_MAX or x < INT_MIN or x == 0)
        {
            return 0;
        }
        long ans = 0;
        while (x != 0)
        {
            ans = ans * 10 + (x % 10);
            if (ans > INT_MAX || ans < INT_MIN)
                return 0;
            x /= 10;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    int x = 0;
    cout << s.reverse(x) << endl;
    return 0;
}