#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }
        else if (r1 == NULL && r2 != NULL)
        {
            return false;
        }
        else if (r1 != NULL && r2 == NULL)
        {
            return false;
        }
        else
        {
            if (r1->val == r2->val)
            {
                return solve(r1->left, r2->right) && solve(r1->right, r2->left);
            }
            else
                return false;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }
        return solve(root->left, root->right);
    }
};
int main()
{

    return 0;
}