#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int max_len = 0;
        int len;
        int now, tmp;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= 0)
            {
                len = 1;
                now = nums[i];
                nums[i] = -1;
                while(nums[now] >= 0 && now != nums[now])
                {
                    ++len;
                    tmp = nums[now];
                    nums[now] = -1;
                    now = tmp;
                }
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    vector<int> nums = {5,4,0,3,1,6,2};
    cout << s.arrayNesting(nums) << endl;
    return 0;
}