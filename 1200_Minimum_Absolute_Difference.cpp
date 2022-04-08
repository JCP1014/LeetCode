#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> res;
        int min_diff = INT_MAX;

        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); ++i)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff)
            {
                min_diff = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            }
            else if (diff == min_diff)
                res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> res = s.minimumAbsDifference(arr);
    for(auto &r: res)
        cout << r[0] << " " << r[1] << endl;

    return 0;
}