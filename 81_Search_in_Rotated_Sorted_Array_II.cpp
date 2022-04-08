#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /******************** Approach 1 ********************
    bool search(vector<int> &nums, int target)
    {
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < nums[i - 1])
                return binarySearch(nums, 0, i - 1, target) ? 1 : binarySearch(nums, i, nums.size() - 1, target);
        }
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    bool binarySearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int m = (start + end) / 2;
            if (target < nums[m])
                end = m - 1;
            else if (target > nums[m])
                start = m + 1;
            else
                return true;
        }
        return false;
    }
    *****************************************************/

    /******************** Approach 2 ********************/
    bool search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int m = (start + end) / 2;
            if (nums[m] == target)
                return true;
            if (nums[m] > nums[start])
            {
                if (target < nums[m] && target >= nums[start])
                    end = m - 1;
                else
                    start = m + 1;
            }
            else if (nums[m] < nums[start])
            {
                if (target > nums[m] && target <= nums[end])
                    start = m + 1;
                else
                    end = m - 1;
            }
            else
                ++start;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 3;

    cout << s.search(nums, target) << endl;

    return 0;
}