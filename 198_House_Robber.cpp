#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp = {nums[0]};
        if (nums.size() > 1)
            dp.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < nums.size(); ++i)
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        return dp.back();
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {2, 1, 1, 2};
    cout << s.rob(nums) << endl;

    return 0;
}