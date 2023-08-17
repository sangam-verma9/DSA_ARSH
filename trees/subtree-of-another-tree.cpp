#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool sameornot(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }
        else if (r1 != NULL && r2 == NULL)
        {
            return false;
        }
        else if (r1 == NULL && r2 != NULL)
        {
            return false;
        }
        else
        {
            if (r1->val == r2->val)
            {
                return sameornot(r1->left, r2->left) && sameornot(r1->right, r2->right);
            }
            else
                return false;
        }
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL)
        {
            return false;
        }
        bool check = sameornot(root, subRoot);
        bool check1 = isSubtree(root->left, subRoot);
        bool check2 = isSubtree(root->right, subRoot);
        return check || check1 || check2;
    }
};
int main()
{

    return 0;
}