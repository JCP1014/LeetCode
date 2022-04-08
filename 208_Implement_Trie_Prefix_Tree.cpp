#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *dict[26];
    bool isEnd;
    TrieNode()
    {
        memset(dict, 0, sizeof(dict));
        isEnd = false;
    }
    ~TrieNode()
    {
        for (auto d : dict)
            delete d;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = this->root;
        for (auto &letter : word)
        {
            if (!node->dict[letter - 'a'])
                node->dict[letter - 'a'] = new TrieNode();
            node = node->dict[letter - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *node = this->root;
        for (auto &letter : word)
        {
            if (!node->dict[letter - 'a'])
                return false;
            node = node->dict[letter - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = this->root;
        for (auto &letter : prefix)
        {
            if (!node->dict[letter - 'a'])
                return false;
            node = node->dict[letter - 'a'];
        }
        return true;
    }

    ~Trie()
    {
        delete root;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Trie *obj = new Trie();
    obj->insert("apple");
    bool res_1 = obj->search("apple");
    bool res_2 = obj->search("app");
    bool res_3 = obj->startsWith("app");
    obj->insert("app");
    bool res_4 = obj->search("app");
    cout << res_1 << endl;
    cout << res_2 << endl;
    cout << res_3 << endl;
    cout << res_4 << endl;

    return 0;
}