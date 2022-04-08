#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie *next[26];
    bool isEnd;
    Trie()
    {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }

    void insert(string &word)
    {
        Trie *node = this;
        for (auto &letter : word)
        {
            int index = letter - 'a';
            if (!node->next[index])
                node->next[index] = new Trie();
            node = node->next[index];
        }
        node->isEnd = true;
    }

    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            delete next[i];
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size();
        n = board[0].size();
        Trie *root = new Trie();

        // Construct the prefix tree
        for (auto &w : words)
            root->insert(w);

        string footprint = "";
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                findNextLetter(board, root, i, j, footprint);
            }
        }
        return ans;
    }
    void findNextLetter(vector<vector<char>> &board, Trie *node, int i, int j, string &footprint)
    {
        if (!node)
            return;
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] == '*')
            return;
        int index = board[i][j] - 'a';
        if (!node->next[index])
            return;
        footprint += board[i][j];
        node = node->next[index];
        if (node->isEnd)
        {
            ans.push_back(footprint);
            node->isEnd = false;
        }
        // Avoid finding a duplicate cell
        board[i][j] = '*';
        findNextLetter(board, node, i - 1, j, footprint);
        findNextLetter(board, node, i + 1, j, footprint);
        findNextLetter(board, node, i, j - 1, footprint);
        findNextLetter(board, node, i, j + 1, footprint);
        // The result of walking this path will be reported back (return feasible),
        // and we need to restore the original letter for trying other paths afterwards.
        board[i][j] = footprint.back();
        footprint.pop_back();
    }

private:
    int m, n;
    vector<string> ans;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> ans = s.findWords(board, words);
    for (auto &a : ans)
        cout << a << endl;

    return 0;
}