#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            q.push(y - x);
        }
        return q.top();
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> stones = {1};

    cout << s.lastStoneWeight(stones) << endl;

    return 0;
}