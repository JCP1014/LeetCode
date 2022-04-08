#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int head = -1;
        for(int i = nums.size()-1; i > 0; --i)
        {
            if (nums[i-1] < nums[i])
            {
                head = i-1;
                break;
            }
        }
        if (head < 0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(int i=nums.size()-1; i>head; --i)
            {
                if (nums[i] > nums[head])
                {
                    swap(nums[i], nums[head]);
                    reverse(nums.begin()+head+1, nums.end());
                    break;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {1,3,2};

    s.nextPermutation(nums);
    for(auto n:nums)
        cout << n << " ";
    cout << endl;

    return 0;
}