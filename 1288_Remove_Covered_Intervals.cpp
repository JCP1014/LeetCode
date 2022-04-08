#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int res = 0;
        int start = -1, end = -1;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });
        for (auto &i : intervals)
        {
            if (i[0] > start && i[1] > end)
            {
                ++res;
                start = i[0];
                end = i[1];
            }
            else if (i[0] == start && i[1] > end)
            {
                end = i[1];
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
    vector<vector<int>> intervals = {{1, 2}, {1, 4}, {3, 4}};

    cout << s.removeCoveredIntervals(intervals) << endl;

    return 0;
}