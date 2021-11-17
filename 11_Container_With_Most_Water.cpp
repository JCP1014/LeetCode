#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int h = min(height[l], height[r]);
        int ans = (r - l) * h;
        while (l < r)
        {
            while (height[l] <= h && l < r)
                ++l;
            while (height[r] <= h && l < r)
                --r;
            h = min(height[l], height[r]);
            ans = max(ans, (r - l) * h);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    vector<int> height = {1,2,1};
    cout << s.maxArea(height) << endl;

    return 0;
}