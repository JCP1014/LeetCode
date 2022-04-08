#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        /********** Approach 1: Compare all 26 frequencies every iteration **********
        if (s2.size() < s1.size())
            return false;

        vector<int> s1_freq(26, 0), window_freq(26, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            ++s1_freq[s1[i] - 'a'];
            ++window_freq[s2[i] - 'a']; // First window in s2
        }
        if (window_freq == s1_freq)
            return true;

        int start = 0;
        for (int end = s1.size(); end < s2.size(); ++end)
        {
            --window_freq[s2[start++] - 'a'];
            ++window_freq[s2[end] - 'a'];
            if (window_freq == s1_freq)
                return true;
        }
        return false;
        *****************************************************************************/

        /********** Approach 2: Compare only 2 frequencies every iteration **********/
        if (s2.size() < s1.size())
            return false;

        vector<int> s1_freq(26, 0), window_freq(26, 0);
        int match_cnt = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            ++s1_freq[s1[i] - 'a'];
            ++window_freq[s2[i] - 'a']; // First window in s2
        }
        for (int i = 0; i < s1_freq.size(); ++i)
        {
            if (window_freq[i] == s1_freq[i])
                ++match_cnt;
        }
        if (match_cnt == 26)
            return true;

        int start = 0;
        int char_index;
        for (int end = s1.size(); end < s2.size(); ++end)
        {
            char_index = s2[start++] - 'a';
            --window_freq[char_index];
            if (window_freq[char_index] == s1_freq[char_index])
                ++match_cnt;
            else if (window_freq[char_index] == s1_freq[char_index] - 1)
                --match_cnt;

            char_index = s2[end] - 'a';
            ++window_freq[char_index];
            if (window_freq[char_index] == s1_freq[char_index])
                ++match_cnt;
            else if (window_freq[char_index] == s1_freq[char_index] + 1)
                --match_cnt;

            if (match_cnt == 26)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string s1 = "ab", s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl;

    return 0;
}