#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (findNextLetter(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool findNextLetter(vector<vector<char>> &board, string &word, int i, int j, int word_index)
    {
        if (word_index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] != word[word_index])
            return false;
        // Avoid finding a duplicate cell
        board[i][j] = '*';
        bool feasible = findNextLetter(board, word, i - 1, j, word_index + 1) ||
                        findNextLetter(board, word, i + 1, j, word_index + 1) ||
                        findNextLetter(board, word, i, j - 1, word_index + 1) ||
                        findNextLetter(board, word, i, j + 1, word_index + 1);
        // The result of walking this path will be reported back (return feasible),
        // and we need to restore the original letter for trying other paths afterwards.
        board[i][j] = word[word_index]; 
        return feasible;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << s.exist(board, word) << endl;

    return 0;
}