#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l = 0, r = matrix.size() - 1;
        int row;
        while (l <= r)
        {
            row = (l + r) / 2;
            if (target >= matrix[row][0] && (row == matrix.size() - 1 || target < matrix[row + 1][0]))
                break;
            else if (target < matrix[row][0])
                r = row - 1;
            else if (target >= matrix[row + 1][0])
                l = row + 1;
        }
        l = 0, r = matrix[row].size()-1;
        if (target > matrix[row][r])
            return false;
        while(l <= r)
        {
            int m = (l+r) / 2;
            if (target == matrix[row][m])
                return true;
            else if (target < matrix[row][m])
                r = m - 1;
            else if (target > matrix[row][m])
                l = m + 1;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13;

    cout << s.searchMatrix(matrix, target) << endl;

    return 0;
}