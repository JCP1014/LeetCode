#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        /************** Approach 1: Hash Map ***************
        unordered_map<int, int> m;
        int cnt = 0;

        for (auto &n : nums)
            ++m[n];
        for (auto e : m)
        {
            if (k > 0)
            {
                if (m.find(e.first + k) != m.end())
                    ++cnt;
            }
            else
            {
                if (e.second > 1)
                    ++cnt;
            }
        }
        return cnt;
        ****************************************************/

        /********* Approach 2: Sorting + Two Pointers **********/
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int small = 0, large = 1;
        while (large < nums.size() && small < nums.size())
        {
            if (nums[large] - nums[small] < k)
                ++large;
            else if (nums[large] - nums[small] > k)
                ++small;
            else
            {
                ++cnt;
                ++small;
                ++large;
                while (small < nums.size() && nums[small] == nums[small - 1])   // Skip same number
                    ++small;
            }

            if (small >= large)
                large = small + 1;
        }
        return cnt;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1, 3, 1, 5, 4};
    int k = 0;

    cout << s.findPairs(nums, k) << endl;

    return 0;
}