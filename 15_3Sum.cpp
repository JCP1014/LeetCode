#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            // Avoid findiing duplicate answers.
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    ++j;
                else if (sum > 0)
                    --k;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {-2, 0, 0, 2, 2};
    vector<vector<int>> ans = s.threeSum(nums);
    for (auto &triplet : ans)
    {
        for (auto &ele : triplet)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}