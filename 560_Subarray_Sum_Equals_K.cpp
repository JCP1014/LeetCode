#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sum_freq;
        int res = 0;
        int sum = 0;
        ++sum_freq[0];
        for (auto n : nums)
        {
            sum += n;
            if (sum_freq.find(sum - k) != sum_freq.end())
                res += sum_freq[sum - k];
            ++sum_freq[sum];
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1, 2, 1, 2, 1};
    int k = 3;

    cout << s.subarraySum(nums, k) << endl;

    return 0;
}