#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> sum12;
        int res = 0;
        for (int n1 : nums1)
            for (int n2 : nums2)
                ++sum12[n1 + n2];
        for (int n3 : nums3)
            for (int n4 : nums4)
                res += sum12[-n3 - n4];
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums1 = {0}, nums2 = {0}, nums3 = {0}, nums4 = {0};

    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    return 0;
}