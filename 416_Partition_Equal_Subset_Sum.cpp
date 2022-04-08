#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        /*********** Approach 1: DP (Slower) ***********************/
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum & 1)    // if sum is odd, return false
            return false;

        sum >>= 1;  // target is half of sum
        vector<bool> reachable(sum + 1, false);
        reachable[0] = true;
        for (auto n : nums)
            for (int i = sum; i >= n; --i)
                reachable[i] = reachable[i] || reachable[i - n];
        return reachable[sum];


        /********** Approach 2: Bit Manipulation (Faster) **********
        int sum = 0;
        for (auto n : nums)
            sum += n;
        if (sum & 1)    // if sum is odd, return false
            return false;
        bitset<200*100+1> b(1);
        for(auto n: nums)
            b = b | (b << n);
        return b[sum >> 1];
        ************************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1,5,11,5};

    cout << s.canPartition(nums) << endl;

    return 0;
}