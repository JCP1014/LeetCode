#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int res = 0;
        int mod = pow(10, 9) + 7;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 2; ++i)
        {
            int j = i + 1;
            int k = arr.size() - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < target)
                    ++j;
                else if (sum > target)
                    --k;
                else
                {
                    if (arr[j] != arr[k])
                    {
                        int j_cnt = 1, k_cnt = 1;
                        while (arr[j] == arr[j + 1])
                        {
                            ++j_cnt;
                            ++j;
                        }
                        while (arr[k] == arr[k - 1])
                        {
                            ++k_cnt;
                            --k;
                        }
                        res += (j_cnt * k_cnt);
                        res %= mod;
                        ++j;
                        --k;
                    }
                    else
                    {
                        res += ((k - j + 1) * (k - j) / 2);
                        res %= mod;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;

    cout << s.threeSumMulti(arr, target) << endl;

    return 0;
}