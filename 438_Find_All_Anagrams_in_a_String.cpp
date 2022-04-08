#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
            return {};
        vector<int> res;
        vector<int> p_table(26, 0);
        vector<int> window_table(26, 0);

        // First window
        for (int i = 0; i < p.size(); ++i)
        {
            ++p_table[p[i] - 'a'];
            ++window_table[s[i] - 'a'];
        }
        if (window_table == p_table)
            res.push_back(0);

        // Slide window
        int head = 0;
        for (int tail = p.size(); tail < s.size(); ++tail)
        {
            --window_table[s[head++] - 'a'];
            ++window_table[s[tail] - 'a'];
            if (window_table == p_table)
                res.push_back(head);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = "aaaaaaaaaa", p = "aaaaaaaaaaaaa";
    vector<int> res = s.findAnagrams(str, p);
    for (auto &r : res)
        cout << r << " ";
    cout << endl;

    return 0;
}