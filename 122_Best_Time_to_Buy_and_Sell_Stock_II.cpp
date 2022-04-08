#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int valley = prices[0];
        int peak;
        bool findValley;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                valley = prices[i];
            }
            if (valley)
            {

            }
        }
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}