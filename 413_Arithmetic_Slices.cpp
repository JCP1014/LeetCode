#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        int res = 0;
        int diff = nums[1] - nums[0];
        int len = 0;

        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == diff)
            {
                ++len;
                res += len;
            }
            else
            {
                len = 0;
                diff = nums[i] - nums[i - 1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1, 2, 3, 4};

    cout << s.numberOfArithmeticSlices(nums) << endl;

    return 0;
}