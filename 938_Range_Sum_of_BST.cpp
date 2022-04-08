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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    TreeNode *n1 = new TreeNode(10);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(13);
    TreeNode *n7 = new TreeNode(18);
    TreeNode *n8 = new TreeNode(1);
    TreeNode *n9 = NULL;
    TreeNode *n10 = new TreeNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n4->right = n9;
    n5->left = n10;

    int low = 6, high = 10;

    cout << s.rangeSumBST(n1, low, high) << endl;

    return 0;
}