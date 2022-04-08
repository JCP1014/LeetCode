#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder, int max_val = INT_MAX)
    {
        if (index == preorder.size() || preorder[index] > max_val)
            return NULL;
        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, max_val);
        return root;
    }

private:
    int index = 0;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution s;
    TreeNode *curr = s.bstFromPreorder(preorder);

    return 0;
}