#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > res.back()[1])
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    vector<vector<int>> res = s.merge(intervals);
    for (auto &r : res)
        cout << r[0] << ", " << r[1] << endl;

    return 0;
}