#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        /******************* Approach 1: sort() *******************
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });
        return vector<vector<int>>(points.begin(), points.begin() + k);
        ***********************************************************/

        /*************** Approach 2: nth_element() ****************/
        nth_element(points.begin(), points.begin() + k, points.end(), [](vector<int> &a, vector<int> &b)
                    { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });
        return vector<vector<int>>(points.begin(), points.begin() + k);

        /*************** Approach 3: Priority Queue ****************
        priority_queue<pair<int, int>> q;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); ++i)
        {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            if (q.size() > k)
                q.pop();
        }
        while(!q.empty())
        {
            res.push_back(points[q.top().second]);
            q.pop();
        }
        return res;
        ************************************************************/
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    vector<vector<int>> res = s.kClosest(points, k);
    for (auto &r : res)
        cout << r[0] << ", " << r[1] << endl;

    return 0;
}