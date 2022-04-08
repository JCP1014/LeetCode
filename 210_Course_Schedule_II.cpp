#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        vector<int> res;
        queue<int> sources;

        for (auto &p : prerequisites)
        {
            ++inDeg[p[0]];
            adj[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (!inDeg[i])
                sources.push(i);
        }
        while (!sources.empty())
        {
            int idx = sources.front();
            res.push_back(idx);
            for (auto &a : adj[idx])
            {
                if (--inDeg[a] == 0)
                    sources.push(a);
            }
            sources.pop();
            --numCourses;
        }
        return (!numCourses) ? res : vector<int>{};
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int numCourses = 1;
    vector<vector<int>> prerequisites = {};
    vector<int> order = s.findOrder(numCourses, prerequisites);
    for(auto &o: order)
        cout << o << endl;

    return 0;
}