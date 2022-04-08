#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPower(string s)
    {
        int cnt = 1;
        int max_cnt = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[i-1])
                ++cnt;
            else
            {
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
            }
        }
        return max(max_cnt, cnt);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = "cc";
    cout << s.maxPower(str) << endl;

    return 0;
}