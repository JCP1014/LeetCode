#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        /*************** Approach 1: 2D Space ***************
        vector<vector<double>> volumes(query_row + 1, vector<double>(query_row + 1, 0));
        volumes[0][0] = poured;
        for (int i = 0; i < query_row; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (volumes[i][j] > 1)
                {
                    volumes[i + 1][j] += (volumes[i][j] - 1) / 2;
                    volumes[i + 1][j + 1] += (volumes[i][j] - 1) / 2;
                    volumes[i][j] = 1;
                }
            }
        }
        return min(1.0, volumes[query_row][query_glass]);
        *****************************************************/

        /*************** Approach 2: 1D Space ***************/
        vector<double> volumes(query_row + 1, 0);
        volumes[0] = poured;
        for (int i = 1; i <= query_row; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                volumes[j] = max(0.0, (volumes[j] - 1) / 2);
                if (j < i)
                    volumes[j + 1] += volumes[j];
            }
        }
        return min(1.0, volumes[query_glass]);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    int poured = 1, query_row = 1, query_glass = 1;
    cout << s.champagneTower(poured, query_row, query_glass) << endl;

    return 0;
}