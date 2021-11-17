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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }

private:
    int sum = 0;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    cout << s.sumOfLeftLeaves(n1) << endl;

    return 0;
}