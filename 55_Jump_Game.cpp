#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        /********** Approach 1: Linear / Greedy (Faster) **********/
        int max_reach = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (max_reach < i)
                return false;
            max_reach = max(max_reach, i + nums[i]);
            if (max_reach >= nums.size() - 1) // nums.size()-1 is the last index
                return true;
        }
        return true;

        /********** Approach 2: DP (Slower) ***********************
        int len = nums.size();
        vector<bool> canReachLast(len, false);
        canReachLast[len - 1] = true;
        for (int i = len - 2; i >= 0; --i)
        {
            for (int j = 1; j <= nums[i]; ++j)
            {
                if (canReachLast[i+j])
                {
                    canReachLast[i] = true;
                    break;
                }
            }
        }
        return canReachLast[0];
        **********************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {3,2,1,0,4};
    cout << s.canJump(nums) << endl;

    return 0;
}