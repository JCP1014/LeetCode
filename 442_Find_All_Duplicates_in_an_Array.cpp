#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        // Approach 1 and 4 are faster
        /********** Approach 1: O(N) **********/
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if (nums[abs(nums[i])-1] > 0)
                ans.push_back(abs(nums[i]));            
        }
        return ans;

        /********** Approach 2: O(2N) **********
        vector<int> ans;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else
                ++i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        }
        return ans;
        ***************************************/

        /********** Approach 3: O(N) ***********
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int j = nums[i] % n;
            if (j == 0)
                j = n;
            if (nums[j-1] > n)
                ans.push_back(j);
            else
                nums[j-1] += n;
        }
        return ans;
        ****************************************/

        /********** Approach 4: O(2N) **********
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            nums[(nums[i] - 1) % n] += n;
        }
        for (int i = 0; i < n; ++i)
        {
            if(nums[i] > 2*n)
                ans.push_back(i+1);
        }
        return ans;
        ****************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;
    ans = s.findDuplicates(nums);
    for (auto &ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}