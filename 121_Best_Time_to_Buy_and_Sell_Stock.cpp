#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> prices = {7,1,5,3,6,4};

    cout << s.maxProfit(prices) << endl;

    return 0;
}