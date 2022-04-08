#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (start < 0 || start >= arr.size() || arr[start] < 0)
            return false;
        if (!arr[start])
            return true;
        arr[start] = -arr[start];
        if (canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]))
            return true;
        arr[start] = -arr[start];
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> arr = {3, 0, 2, 1, 2};
    int start = 2;

    cout << s.canReach(arr, start) << endl;

    return 0;
}