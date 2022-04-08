#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string ans = "";
        vector<int> digits(num1.size() + num2.size(), 0);
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            for (int i = num1.size() - 1; i >= 0; --i)
            {
                digits[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                digits[i + j] += digits[i + j + 1] / 10;
                digits[i + j + 1] %= 10;
            }
        }

        for (auto d : digits)
            if (ans.size() || d)
                ans += to_string(d);

        if (!ans.size())
            return "0";

        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string num1 = "123", num2 = "456";
    cout << s.multiply(num1, num2) << endl;

    return 0;
}