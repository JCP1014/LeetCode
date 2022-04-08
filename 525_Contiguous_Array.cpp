#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> hm; // hash map
        int maxLength = 0;
        int count = 0;

        hm[0] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            count += (nums[i]) ? 1 : -1;
            if (hm.find(count) != hm.end())
                maxLength = max(maxLength, i - hm[count]);
            else
                hm[count] = i;
        }
        return maxLength;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {0, 1, 0};
    cout << s.findMaxLength(nums) << endl;

    return 0;
}