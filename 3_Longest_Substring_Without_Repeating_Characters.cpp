#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // We took size of dict 256 as all ASCII code is upto 256.
        vector<int> dict(256, -1);
        int start = -1;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;

    return 0;
}