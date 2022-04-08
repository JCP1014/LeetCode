#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;
        bool up = true;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] == arr[i - 1])
                return false;
            if (up)
            {
                if (arr[i] < arr[i - 1])
                {
                    if (i > 1)
                        up = false;
                    else
                        return false;
                }
            }
            else
            {
                if (arr[i] > arr[i - 1])
                    return false;
            }
        }
        return !up;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> arr = {3, 5, 5};
    cout << s.validMountainArray(arr) << endl;
    return 0;
}