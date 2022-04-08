#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        /********** Approach 1 **********/
        int aXORb = 0;
        int mask = 1;
        int a = 0;
        for (auto &n : nums)
            aXORb ^= n;
        while (!(aXORb & mask))
            mask <<= 1;
        for (auto &n : nums)
            if (n & mask)
                a ^= n;
        return {a, aXORb ^ a};

        /********** Approach 2 **********
        long aXORb = 0;
        int a = 0;
        for (auto &n : nums)
            aXORb ^= n;
        for (auto &n : nums)
            if (aXORb & -aXORb & n)
                a ^= n;
        return {a, int(aXORb) ^ a};
        *********************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = s.singleNumber(nums);
    for (auto &n : ans)
        cout << n << endl;

    return 0;
}