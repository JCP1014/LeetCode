#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<vector<int>> adj(n); // adjacency list
        vector<int> deg(n, 0);      // degree
        queue<int> leaves;
        vector<int> roots;

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            ++deg[e[0]];
            ++deg[e[1]];
        }

        for (int i = 0; i < n; ++i)
            if (deg[i] == 1)
                leaves.push(i);

        while (leaves.size())
        {
            int layer_nodes = leaves.size();
            roots.clear();
            for (int i = 0; i < layer_nodes; ++i)
            {
                roots.push_back(leaves.front());
                for (auto &a : adj[leaves.front()])
                    if (--deg[a] == 1)
                        leaves.push(a);
                leaves.pop();
            }
        }
        return roots;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int n = 6;
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> res = s.findMinHeightTrees(n, edges);
    for (auto &r : res)
        cout << r << endl;

    return 0;
}