#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i)
            swap(s[i], s[n - 1 - i]);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<char> s = {'H','a','n','n','a', 'h'};
    sol.reverseString(s);
    for(auto c:s)
        cout << c;
    cout << endl;

    return 0;
}