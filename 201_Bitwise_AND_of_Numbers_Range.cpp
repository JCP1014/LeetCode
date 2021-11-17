#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        return (right > left) ? rangeBitwiseAnd(left / 2, right / 2) << 1 : left;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}