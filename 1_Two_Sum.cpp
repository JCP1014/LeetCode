#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = umap.find(target - nums[i]);
            if (umap.find(target - nums[i]) != umap.end())
            {
                return {i, iter->second};
            }
            umap[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums{3, 3};
    int target = 6;
    Solution s;
    vector<int> ans = s.twoSum(nums, target);
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << *it << endl;
}