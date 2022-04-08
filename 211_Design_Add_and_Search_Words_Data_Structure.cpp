#include <bits/stdc++.h>
using namespace std;

/****************** Approach 1: Trie ******************
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
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *curr = root;
        for (auto &ch : word)
        {
            int index = ch - 'a';
            if (!curr->dict[index])
            {
                curr->dict[index] = new TrieNode();
            }
            curr = curr->dict[index];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        return helper(root, word);
    }
    bool helper(TrieNode *node, string word)
    {
        if (!node)
            return false;
        TrieNode *curr = node;
        for (int i = 0; i < word.size(); ++i)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (helper(curr->dict[j], word.substr(i + 1)))
                        return true;
                }
                return false;
            }
            else
            {
                if (!curr->dict[word[i] - 'a'])
                    return false;
                curr = curr->dict[word[i] - 'a'];
            }
        }
        return curr->isEnd;
    }

private:
    TrieNode *root;
};
*******************************************************/

/*************** Approach 2: Hash Table ***************/
class WordDictionary
{
public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        dictionary[word.size()].push_back(word);
    }

    bool search(string word)
    {
        for (auto &a : dictionary[word.size()])
            if (isEqual(a, word))
                return true;
        return false;
    }
    bool isEqual(string a, string b)
    {
        for (int i = 0; i < a.size(); ++i)
            if (b[i] != '.' && a[i] != b[i])
                return false;
        return true;
    }

private:
    unordered_map<int, vector<string>> dictionary;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    WordDictionary *obj = new WordDictionary();
    // obj->addWord("bad");
    // obj->addWord("dad");
    // obj->addWord("mad");
    // cout << obj->search("pad") << endl; // return False
    // cout << obj->search("bad") << endl; // return True
    // cout << obj->search(".ad") << endl; // return True
    // cout << obj->search("b..") << endl; // return True

    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");
    cout << obj->search("a") << endl;   // return False
    cout << obj->search(".at") << endl; // return False
    obj->addWord("bat");
    cout << obj->search(".at") << endl;  // return True
    cout << obj->search("an.") << endl;  // return True
    cout << obj->search("a.d.") << endl; // return False
    cout << obj->search("b.") << endl;   // return False
    cout << obj->search("a.d") << endl;  // return True
    cout << obj->search(".") << endl;    // return False

    return 0;
}