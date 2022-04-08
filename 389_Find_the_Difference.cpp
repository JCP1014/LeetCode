#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        /***** Approach 1: XOR *****/
        char res = 0;
        for (auto c : s)
            res ^= c;
        for (auto c : t)
            res ^= c;
        return res;

        /***** Approach 2: Sum Difference *****
        char sum = 0;
        for (auto c : t)
            sum += c;
        for (auto c : s)
            sum -= c;
        return sum;
        ***************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "", t = "y";

    cout << sol.findTheDifference(s, t) << endl;

    return 0;
}