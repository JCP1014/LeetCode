#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *next[2];
    TrieNode() { next[0] = NULL, next[1] = NULL; };
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *root = buildTrie(nums);
        int res = 0;
        for (auto &n : nums)
        {
            res = max(res, getXOR(root, n));
        }
        return res;
    }
    TrieNode *buildTrie(vector<int> &nums)
    {
        TrieNode *root = new TrieNode();
        for (auto &n : nums)
        {
            TrieNode *curr = root;
            for (int i = 31; i >= 0; --i)
            {
                bool bit = n & (1 << i);
                if (!curr->next[bit])
                    curr->next[bit] = new TrieNode();
                curr = curr->next[bit];
            }
        }
        return root;
    }
    int getXOR(TrieNode *root, int n)
    {
        int res = 0;
        TrieNode *curr = root;
        for (int i = 31; i >= 0; --i)
        {
            bool bit = n & (1 << i);
            if (curr->next[!bit])
            {
                res <<= 1;
                res += 1;
                curr = curr->next[!bit];
            }
            else
            {
                res <<= 1;
                curr = curr->next[bit];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};

    cout << s.findMaximumXOR(nums) << endl;

    return 0;
}