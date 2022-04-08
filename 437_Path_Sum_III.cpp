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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return dfs(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(TreeNode *node, int targetSum, int currSum)
    {
        if (!node)
            return 0;
        currSum += node->val;
        return (currSum == targetSum) + dfs(node->left, targetSum, currSum) + dfs(node->right, targetSum, currSum);
        ;
    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(8);
    TreeNode *n4 = new TreeNode(11);
    TreeNode *n5 = new TreeNode(13);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(2);
    TreeNode *n9 = new TreeNode(5);
    TreeNode *n10 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;
    n4->left = n7;
    n4->right = n8;
    n6->left = n9;
    n6->right = n10;

    Solution s;
    int targetSum = 22;
    cout << s.pathSum(n1, targetSum) << endl;

    return 0;
}