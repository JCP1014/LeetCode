#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> cnt(26, 0);
        vector<bool> isUsed(26, 0);
        string res = "";

        for (auto c : s)
            ++cnt[c - 'a'];
        for (auto c : s)
        {
            --cnt[c - 'a'];
            if (!isUsed[c - 'a'])
            {
                while (!res.empty() && res.back() > c && cnt[res.back() - 'a'])
                {
                    isUsed[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                isUsed[c - 'a'] = true;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    string s = "cbacdcbc";

    cout << sol.removeDuplicateLetters(s) << endl;

    return 0;
}