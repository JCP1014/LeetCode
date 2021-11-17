#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int d = prices.size();
        if (d == 1)
            return 0;
        if (d == 2)
            return max(0, -prices[0] + prices[1]);
        vector<int> buy(d, 0);
        vector<int> sell(d, 0);
        buy[0] = -prices[0];
        buy[1] = -prices[1];
        sell[1] = -prices[0] + prices[1];
        int max_profit = max(0, sell[1]);
        for (int i = 2; i < d; ++i)
        {
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
            max_profit = max(max_profit, sell[i]);
        }
        return max_profit;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> prices = {1,4,2};
    cout << s.maxProfit(prices) << endl;

    return 0;
}