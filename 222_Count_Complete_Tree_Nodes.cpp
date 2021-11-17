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
    int countNodes(TreeNode *root)
    {
        /***************** Approach 1 (Recursive) ******************/
        if (!root)
            return 0;
        int lh = 0, rh = 0;
        TreeNode *curr = root;
        while (curr)
        {
            ++lh;
            curr = curr->left;
        }
        curr = root;
        while (curr)
        {
            ++rh;
            curr = curr->right;
        }
        if (lh == rh)
            return (1 << lh) - 1;   // or pow(2, lh) - 1
        return 1 + countNodes(root->left) + countNodes(root->right);

        /*************** Approach 2 (Non-recursive) ***************
        if (!root)
            return 0;
        int lh = 0;
        int num = 0;
        for (TreeNode *node = root->left; node; node = node->left)
            ++lh;
        while (root)
        {
            int rh = 0;
            for (TreeNode *node = root->right; node; node = node->left)
                ++rh;
            if (lh == rh)
            {
                num += (1 << lh);
                root = root->right;
            }
            else
            {
                num += (1 << rh);
                root = root->left;
            }
            --lh;
        }
        return num;
        ***********************************************************/

    }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution s;
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;

    cout << s.countNodes(n1) << endl;
    return 0;
}