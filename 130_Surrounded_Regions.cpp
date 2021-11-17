#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                span(board, 0, j);
            if (board[m - 1][j] == 'O')
                span(board, m - 1, j);
        }
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                span(board, i, 0);
            if (board[i][n - 1] == 'O')
                span(board, i, n - 1);
        }
        for (auto &row : board)
            for (auto &ele : row)
                ele = (ele == '*') ? 'O' : 'X';
    }
    void span(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = '*';
        if (i + 1 < m && board[i + 1][j] == 'O')
            span(board, i + 1, j);
        if (j + 1 < n && board[i][j + 1] == 'O')
            span(board, i, j + 1);
        if (i - 1 >= 0 && board[i - 1][j] == 'O')
            span(board, i - 1, j);
        if (j - 1 >= 0 && board[i][j - 1] == 'O')
            span(board, i, j - 1);
    }

private:
    int m, n;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);

    return 0;
}