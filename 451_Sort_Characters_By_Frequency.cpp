#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        /***************** Approach 1 *****************
        vector<string> record(128, "");
        string ans = "";
        for (auto c : s)
        {
            record[c] += c;
        }
        sort(record.begin(), record.end(), [](string &a, string &b)
             { return a.size() > b.size(); });
        for (auto str : record)
            ans += str;
        return ans;
        **********************************************/

        /********** Approach 2: Bucket Sort **********
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        string ans = "";
        for (auto &c : s)
            ++freq[c];
        for (auto &f : freq)
            bucket[f.second].append(f.second, f.first);
        for (int i = s.size(); i > 0; --i)
            ans.append(bucket[i]);
        return ans;
        **********************************************/

        /********** Approach 3: Priority Queue **********/
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> q;
        string ans;
        for (auto &c : s)
            ++freq[c];
        for (auto &f : freq)
            q.push({f.second, f.first});
        while (!q.empty())
        {
            auto tmp = q.top();
            ans.append(tmp.first, tmp.second);
            q.pop();
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    string str = "Aabb";
    cout << s.frequencySort(str) << endl;

    return 0;
}