#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        for (auto &w : word)
        {
            if (isupper(w))
                ++cnt;
        }
        return (!cnt) || (cnt == word.size()) || (cnt == 1 && isupper(word[0]));
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string word = "leetcode";

    cout << s.detectCapitalUse(word) << endl;

    return 0;
}