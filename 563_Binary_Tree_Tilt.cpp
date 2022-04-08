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
    int findTilt(TreeNode *root)
    {
        dfs(root);
        return tilt_sum;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);
        tilt_sum += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;
    }

private:
    int tilt_sum = 0;
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    TreeNode *n1 = new TreeNode(21);
    TreeNode *n2 = new TreeNode(7);
    TreeNode *n3 = new TreeNode(14);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(1);
    TreeNode *n6 = new TreeNode(2);
    TreeNode *n7 = new TreeNode(2);
    TreeNode *n8 = new TreeNode(3);
    TreeNode *n9 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n4->right = n9;

    cout << s.findTilt(n1) << endl;

    return 0;
}