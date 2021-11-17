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
    /******************** Approach 1: DFS ***********************
    bool isCousins(TreeNode *root, int x, int y)
    {
        int x_depth = dfs(root, 0, x, y);
        return (x_depth) ? (x_depth == dfs(root, 0, y, x)) : 0;
    }
    int dfs(TreeNode *node, int depth, int v1, int v2)
    {
        if (node->left && node->right)
        {
            if (node->left->val == v1)
            {
                if (node->right->val == v2)
                    return 0;
                return depth + 1;
            }
            else if (node->right->val == v1)
            {
                if (node->left->val == v2)
                    return 0;
                return depth + 1;
            }
            else
            {
                int l_res = dfs(node->left, depth + 1, v1, v2);
                return (l_res) ? l_res : dfs(node->right, depth + 1, v1, v2);
            }
        }
        if (node->left)
        {
            if (node->left->val == v1)
                return depth + 1;
            return dfs(node->left, depth + 1, v1, v2);
        }
        if (node->right)
        {
            if (node->right->val == v1)
                return depth + 1;
            return dfs(node->right, depth + 1, v1, v2);
        }
        return 0;
    }
    ****************************************************************/

    /******************** Approach 2: DFS + map ********************/
    


    /******************** Approach 3: Level-order traversal ********************
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> q, qc;
        bool findOne = false, isSibling = false;
        q.push(root);
        while (!q.empty() && !findOne)
        {
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();
                if (!node)
                    isSibling = false;
                else
                {
                    if (node->val == x || node->val == y)
                    {
                        if (!findOne)
                            findOne = isSibling = true;
                        else
                            return !isSibling;
                    }
                    qc.push(node->left), qc.push(node->right), qc.push(NULL);
                }
            }
            swap(q, qc);
        }
        return false;
    ***************************************************************************/
}
}
;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->right = n4;

    Solution s;
    int x = 2, y = 3;
    cout << s.isCousins(n1, x, y) << endl;

    return 0;
}