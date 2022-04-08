#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        /*************** Approach 1: Set ***************
        set<pair<int, int>> s;
        vector<int> res;

        for (int i = 0; i < mat.size(); ++i)
        {
            int cnt = 0;
            for (int j = 0; j < mat[0].size(); ++j)
                cnt = (mat[i][j]) ? cnt + 1 : cnt;
            s.insert({cnt, i});
        }
        for (auto p : s)
        {
            if (k--)
                res.push_back(p.second);
            else
                return res;
        }
        return res;
        ************************************************/

        /********** Approach 2: Vector with Sorting **********
        vector<pair<int, int>> v;
        vector<int> res;

        for (int i = 0; i < mat.size(); ++i)
        {
            int cnt = 0;
            for (int j = 0; j < mat[0].size(); ++j)
                cnt = (mat[i][j]) ? cnt + 1 : cnt;
            v.push_back({cnt, i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k; ++i)
            res.push_back(v[i].second);
        return res;
        ******************************************************/

        /*************** Approach 3: Without Sorting ***************/
        vector<int> res;
        vector<bool> pushed(mat.size(), 0);

        for (int j = 0; j <= mat[0].size(); ++j)
        {
            for (int i = 0; i < mat.size(); ++i)
            {
                if (!pushed[i] && (j == mat[0].size() || !mat[i][j]))
                {
                    res.push_back(i);
                    pushed[i] = true;
                    if (res.size() == k)
                        return res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 1, 1},
                               {1, 0, 0, 0},
                               {1, 0, 0, 0}};
    int k = 2;

    vector<int> res = s.kWeakestRows(mat, k);
    for (auto r : res)
        cout << r << endl;

    return 0;
}