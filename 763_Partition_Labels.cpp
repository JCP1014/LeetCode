#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> lastIndex(26);
        vector<int> res;
        for (int i = 0; i < s.size(); ++i)
            lastIndex[s[i] - 'a'] = i;

        int start = 0;
        int end = lastIndex[s[0] - 'a'];
        for (int i = 0; i < s.size(); ++i)
        {
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
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
    string s = "ababcbacadefegdehijhklij";

    vector<int> res = sol.partitionLabels(s);
    for (auto r : res)
        cout << r << endl;

    return 0;
}