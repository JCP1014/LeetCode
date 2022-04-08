#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1; 
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int num = 0;
    cout << s.addDigits(num) << endl;

    return 0;
}