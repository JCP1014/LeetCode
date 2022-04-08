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
        int maxFirstBuy = -prices[0];
        int maxFirstSell = 0;
        int maxSecondBuy = -prices[1];
        int maxSecondSell = 0;
        int currFirstBuy, currFirstSell, currSecondBuy, currSecondSell;
        for (int i = 1; i < d; ++i)
        {
            currFirstBuy = max(maxFirstBuy, -prices[i]);
            currFirstSell = max(maxFirstSell, maxFirstBuy + prices[i]);
            currSecondBuy = max(maxSecondBuy, maxFirstSell - prices[i]);
            currSecondSell = max(maxSecondSell, maxSecondBuy + prices[i]);
            maxFirstBuy = currFirstBuy;
            maxFirstSell = currFirstSell;
            maxSecondBuy = currSecondBuy;
            maxSecondSell = currSecondSell;
        }
        return max(maxFirstSell, maxSecondSell);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << s.maxProfit(prices) << endl;

    return 0;
}