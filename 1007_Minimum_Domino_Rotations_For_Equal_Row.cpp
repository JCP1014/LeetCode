#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        /******************** Approach 1 ********************
        vector<int> cnt_top(7, 0), cnt_bot(7, 0), cnt_same(7, 0);
        int n = tops.size();
        for (int i = 0; i < n; ++i)
        {
            ++cnt_top[tops[i]];
            ++cnt_bot[bottoms[i]];
            if (tops[i] == bottoms[i])
                ++cnt_same[tops[i]];
        }
        for (int i = 1; i < 7; ++i)
            if (cnt_top[i] + cnt_bot[i] - cnt_same[i] == n)
                return n - max(cnt_top[i], cnt_bot[i]);
        return -1;
        *****************************************************/

        /******************** Approach 2 ********************/
        int res = helper(tops, bottoms, tops[0]);
        if (res != -1)
            return res;
        return helper(tops, bottoms, bottoms[0]);
    }
    // For Approach 2
    int helper(vector<int> &tops, vector<int> &bottoms, int target)
    {
        int top_rotate = 0, bottom_rotate = 0;
        for (int i = 0; i < tops.size(); ++i)
        {
            if (tops[i] != target && bottoms[i] != target)
                return -1;
            else if (tops[i] != target)
                ++top_rotate;
            else if (bottoms[i] != target)
                ++bottom_rotate;
        }
        return min(top_rotate, bottom_rotate);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> tops = {2, 1, 2, 4, 2, 2}, bottoms = {5, 2, 6, 2, 3, 2};

    cout << s.minDominoRotations(tops, bottoms) << endl;

    return 0;
}