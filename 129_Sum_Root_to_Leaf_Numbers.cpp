#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        return dfs(root, 0);
    }
    int dfs(TreeNode *node, int num)
    {
        if(!node)
            return 0;
        if (!node->left && !node->right)
            return num*10 + node->val;
        return dfs(node->left, num * 10 + node->val) + dfs(node->right, num * 10 + node->val);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    cout << s.sumNumbers(n1) << endl;

    return 0;
}
