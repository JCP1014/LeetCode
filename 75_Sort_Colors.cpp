#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /********** Approach 1: Counting Sort (Two-pass) **********/
        int cnt[3] = {0};
        for (auto &color : nums)
            ++cnt[color];
        int index = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                nums[index++] = i;

        /****************** Approach 2: One-pass ******************
        int p = 0;
        int l = 0, r = nums.size() - 1;
        while (p <= r)
        {
            if (nums[p] == 0)
                swap(nums[p++], nums[l++]);
            else if (nums[p] == 2)
                swap(nums[p], nums[r--]);
            else
                ++p;
        }
        ***********************************************************/

    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);

    return 0;
}