#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int len1 = nums1.size();
        int len2 = nums2.size();
        int l = 0;
        int r = len1;
        int cut1, cut2;
        double leftMax1, rightMin1;
        double leftMax2, rightMin2;
    
        cut1 = l + (r - l) / 2;
        while (1)
        {
            cut2 = (len1 + len2) / 2 - cut1;
            leftMax1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            rightMin1 = (cut1 == len1) ? INT_MAX : nums1[cut1];
            leftMax2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            rightMin2 = (cut2 == len2) ? INT_MAX : nums2[cut2];
            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1)
            {
                if ((len1 + len2) % 2 == 0)
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2;
                else
                    return min(rightMin1, rightMin2);
            }
            else
            {
                if (leftMax1 > rightMin2)
                    --cut1;
                else // leftMax2 > rightMin1
                    ++cut1;
            }
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    vector<int> nums1, nums2;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
