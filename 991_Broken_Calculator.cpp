#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        /*************** Approach 1: Iterative ***************/
        int res = 0;
        while (startValue < target)
        {
            target = (target & 1) ? target + 1 : target / 2;
            ++res;
        }
        return res + (startValue - target);

        /*************** Approach 2: Recursive ***************
        if (startValue >= target)
            return startValue - target;
        return (target & 1) ? 1 + brokenCalc(startValue, target + 1) : 1 + brokenCalc(startValue, target / 2);
        ******************************************************/
    
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int startValue = 5, target = 8;

    cout << s.brokenCalc(startValue, target) << endl;

    return 0;
}