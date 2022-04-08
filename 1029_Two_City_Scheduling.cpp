#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        /*************** Approach 1: Less Memory, More Time ***************/
        int res = 0;
        int n = costs.size() / 2;

        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b)
             { return (a[0] - a[1]) < (b[0] - b[1]); });
        for (int i = 0; i < n; ++i)
            res += costs[i][0] + costs[n + i][1];
        return res;

        /*************** Approach 2: Less Time, More Memory ***************
        int res = 0;
        vector<int> diff;

        for (auto c : costs)
        {
            res += c[0];
            diff.push_back(c[1] - c[0]);
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < costs.size() / 2; ++i)
            res += diff[i];
        return res;
        *******************************************************************/

    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> costs = {{515, 563}, {451, 713}, {537, 709}, {343, 819}, {855, 779}, {457, 60}, {650, 359}, {631, 42}};

    cout << s.twoCitySchedCost(costs) << endl;

    return 0;
}