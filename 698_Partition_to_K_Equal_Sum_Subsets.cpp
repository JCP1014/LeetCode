#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(vector<int> &nums, int k, int target_sum, int curr_sum, vector<bool> &visited, int index)
    {
        if (!k)
            return true;
        if (curr_sum == target_sum)
            return helper(nums, --k, target_sum, 0, visited, 0);
        for (int i = index; i < nums.size(); ++i)
        {
            if (visited[i] || curr_sum + nums[i] > target_sum)
                continue;
            visited[i] = true;
            if (helper(nums, k, target_sum, curr_sum + nums[i], visited, i + 1))
                return true;
            visited[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int len = nums.size();
        int total = 0;
        for (int i = 0; i < len; ++i)
        {
            total += nums[i];
        }
        if (total % k || len < k)
            return false;
        int target = total / k;
        vector<bool> visited(len, false);
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return helper(nums, k, target, 0, visited, 0);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout << s.canPartitionKSubsets(nums, k) << endl;

    return 0;
}