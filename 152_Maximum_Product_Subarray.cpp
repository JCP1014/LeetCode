#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        /*********** Approach 1: Two-pass ***********
        int max_product = nums[0];
        int product = 1;
        for (int i=0; i<nums.size(); ++i)
        {
            product *= nums[i];
            max_product = max(max_product, product);
            if (nums[i] == 0)
                product = 1;
        }
        product = 1;
        for(int i=nums.size()-1; i>=0; --i)
        {
            product *= nums[i];
            max_product = max(max_product, product);
            if (nums[i] == 0)
                product = 1;
        }
        return max_product;
        *********************************************/

        /*********** Approach 2: One-pass ***********/
        int max_product = nums[0];
        int left_product = 1;
        int right_product = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            left_product *= nums[i];
            right_product *= nums[n - 1 - i];
            max_product = max(max_product, max(left_product, right_product));
            if (nums[i] == 0)
                left_product = 1;
            if (nums[n-1-i] == 0)
                right_product = 1;
        }
        return max_product;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {3, -1, 4};
    cout << s.maxProduct(nums) << endl;

    return 0;
}