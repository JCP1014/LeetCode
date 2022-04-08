#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {

        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2)
        {
            while (i < nums.size() && !(nums[i] % 2))
                i += 2;
            while (j < nums.size() && nums[j] % 2)
                j += 2;
            if (i < nums.size())
                swap(nums[i], nums[j]);
        }
        return nums;
        
        /********** My Approach **********
        int cnt = 0;
        int half = nums.size() / 2;
        bool even = true;
        int j;
        for (int i = 0; i < nums.size() && cnt < half; ++i)
        {
            if (even)
            {
                if (nums[i] % 2)
                {
                    j = i + 1;
                    while (nums[j] % 2)
                        j += 2;
                    swap(nums[i], nums[j]);
                }
                cnt += 1;
            }
            else
            {
                if (nums[i] % 2 == 0)
                {
                    j = i + 1;
                    while (nums[j] % 2 == 0)
                        j += 2;
                    swap(nums[i], nums[j]);
                }
            }
            even = !even;
        }
        return nums;
        *********************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums = {2, 3};
    Solution s;
    nums = s.sortArrayByParityII(nums);
    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}