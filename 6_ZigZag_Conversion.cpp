#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        /********** Approach 1 (Intuitive, but slower, and need more space) **********
        if (numRows == 1)
            return s;
        vector<string> v(min(numRows, int(s.size())));
        int row = 0;
        int step = 1;
        string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            v[row] += s[i];
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }
        for (int i = 0; i < v.size(); ++i)
        {
            ans += v[i];
        }
        return ans;
        ****************************************************************************/

        /********** Approach 2 (Faster, and need less space) **********/
        if (numRows == 1)
            return s;
        string ans;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        int i, j;
        for (int row = 0; row < numRows; ++row)
        {
            i = row;
            j = cycleLen - i;
            while (i < n)
            {
                ans += s[i];
                if (row > 0 && row < numRows - 1 && j < n)
                {
                    ans += s[j];
                    j += cycleLen;
                }
                i += cycleLen;
            }
        }
        return ans; 
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 4;
    cout << s.convert(str, numRows) << endl;

    return 0;
}
