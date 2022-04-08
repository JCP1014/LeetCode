#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        /*************** Approach 1: Math ***************
        string n_str = to_string(n);
        int n_len = n_str.size();
        int num = digits.size();
        int sum = 0;

        for (int i = 1; i < n_len; ++i)
            sum += pow(num, i);

        for (int i = 0; i < n_len; ++i)
        {
            bool canStop = true;
            for (auto &d : digits)
            {
                if (d[0] < n_str[i])
                    sum += pow(num, n_len - i - 1);
                else if (d[0] > n_str[i])
                    break;
                else    // d[0] == n_str[i]
                {
                    if (i == n_len-1)
                        sum += 1;
                    canStop = false;
                    break;
                }
            }
            if (canStop)
                break;
        }
        return sum;
        *************************************************/

        /**************** Approach 2: DP ****************/
        string n_str = to_string(n);
        int n_len = n_str.size();
        vector<int> dp(n_len + 1, 0);
        int num = digits.size();
        dp[n_len] = 1;
        for (int i = n_len - 1; i >= 0; --i)
        {
            for (auto d : digits)
            {
                if (d[0] < n_str[i])
                    dp[i] += pow(num, n_len - 1 - i);
                else if (d[0] == n_str[i])
                {
                    dp[i] += dp[i + 1];
                    break;
                }
                else
                    break;
            }
        }
        for (int i = 1; i < n_len; ++i)
            dp[0] += pow(num, i);

        return dp[0];
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<string> digits = {"1", "3", "5", "7"};
    int n = 100;

    cout << s.atMostNGivenDigitSet(digits, n) << endl;

    return 0;
}