#include <bits/stdc++.h>
using namespace std;
//******* good but space not optimized ******* here we create a new tree ***
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        else if (root1 != NULL && root2 == NULL)
        {
            return root1;
        }
        else if (root1 == NULL && root2 != NULL)
        {
            return root2;
        }
        else
        {
            TreeNode *root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        }
    }
};
// ******* optimized ***** here we merge second tree in to first ****
class Solution
{
public:
    void solve(TreeNode *&r1, TreeNode *&r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return;
        }
        else if (r1 != NULL && r2 == NULL)
        {
            return;
        }
        else if (r1 == NULL && r2 != NULL)
        {
            r1 = r2;
        }
        else
        {
            r1->val += r2->val;
            solve(r1->left, r2->left);
            solve(r1->right, r2->right);
        }
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        solve(root1, root2);
        return root1;
    }
};
//********
int main()
{

    return 0;
}