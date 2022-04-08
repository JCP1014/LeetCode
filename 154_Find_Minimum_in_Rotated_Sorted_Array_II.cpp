#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        /*************** Approach 1 ***************
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i-1])
                return nums[i];
        }
        return nums[0];
        *******************************************/

        /******* Approach 2: Bunary Search ********/
        int l = 0, r = nums.size() - 1;
        int m;
        while (l < r)
        {
            m = (l + r) / 2;
            if (nums[m] < nums[r])
                r = m;
            else if (nums[m] > nums[r])
                l = m + 1;
            else
                --r;
        }
        return nums[r]; // nums[l] is also right because finally l==r
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << s.findMin(nums) << endl;

    return 0;
}