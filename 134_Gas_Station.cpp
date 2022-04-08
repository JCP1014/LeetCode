#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total_gain = 0;
        int remain = 0;
        int start_index = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            total_gain += (gas[i] - cost[i]);
            remain += gas[i] - cost[i];
            if (remain < 0)
            {
                start_index = i + 1;
                remain = 0;
            }
        }
        return (total_gain < 0) ? -1 : start_index;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};

    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}