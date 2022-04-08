#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        /*************** Approach 5: Binary Search ***************/
        int lo = 1, hi = nums.size() - 1;
        int res = 0;
        while (lo <= hi)
        {
            int m = (lo + hi) / 2;
            int cnt = 0;
            for (auto num : nums)
                if (num <= m)
                    ++cnt;
            if (cnt > m)
            {
                res = m;
                hi = m - 1;
            }
            else
                lo = m + 1;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {3, 1, 3, 4, 2};

    cout << s.findDuplicate(nums) << endl;

    return 0;
}