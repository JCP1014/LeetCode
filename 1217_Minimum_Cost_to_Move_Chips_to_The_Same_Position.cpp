#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;
        for (auto p : position)
        {
            if (p & 1)
                ++odd;
            else
                ++even;
        }
        return min(odd, even);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> position = {1,1000000000};
    cout << s.minCostToMoveChips(position) << endl;

    return 0;
}