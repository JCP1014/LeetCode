#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int res = 0;
        int l = 0;
        sort(people.begin(), people.end());
        for (int r = people.size() - 1; r >= l; --r)
        {
            if (people[r] + people[l] <= limit)
                ++l;
            ++res;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> people = {2, 49, 10, 7, 11, 41, 47, 2, 22, 6, 13, 12, 33, 18, 10, 26, 2, 6, 50, 10};
    int limit = 50;

    cout << s.numRescueBoats(people, limit) << endl;

    return 0;
}