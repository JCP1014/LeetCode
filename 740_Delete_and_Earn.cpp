#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        /********** Approach 1: DP without optimized **********
        int MAX_NUM = 10000;
        vector<int> sums(MAX_NUM + 1, 0);
        vector<int> dp(MAX_NUM + 1, 0);

        for (auto n : nums)
            sums[n] += n;

        dp[1] = sums[1];
        for (int i = 2; i <= MAX_NUM; ++i)
            dp[i] = max(dp[i - 2] + sums[i], dp[i - 1]);

        return dp[MAX_NUM];
        *****************************************************/

        /************* Approach 2: Optimized DP *************
        int MAX_NUM = 10000;
        vector<int> sums(MAX_NUM + 1, 0);
        int pprev, prev, curr;

        for (auto n : nums)
            sums[n] += n;

        pprev = 0;
        prev = sums[1];
        for (int i = 2; i <= MAX_NUM; ++i)
        {
            curr = max(pprev + sums[i], prev);
            pprev = prev;
            prev = curr;
        }
        return curr;
        *****************************************************/

        /*********** Approach 3: DP with Hash map  **********/
        int max_num = 0;
        unordered_map<int, int> num_cnt;

        for (auto n : nums)
        {
            ++num_cnt[n];
            max_num = max(max_num, n);
        }

        vector<int> dp(max_num + 1, 0);
        dp[1] = num_cnt[1];
        for (int i = 2; i <= max_num; ++i)
            dp[i] = max(dp[i - 2] + i * num_cnt[i], dp[i - 1]);

        return dp[max_num];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    cout << s.deleteAndEarn(nums) << endl;

    return 0;
}