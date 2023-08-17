#include <bits/stdc++.h>
using namespace std;
//********* first approach *******
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode *leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightans = lowestCommonAncestor(root->right, p, q);
        if (leftans != NULL && rightans != NULL)
        {
            return root;
        }
        else if (leftans != NULL && rightans == NULL)
        {
            return leftans;
        }
        else if (leftans == NULL && rightans != NULL)
        {
            return rightans;
        }
        else
        {
            return NULL;
        }
    }
};
//***********
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode *leftans = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightans = lowestCommonAncestor(root->right, p, q);
        if (leftans != NULL && rightans != NULL)
        {
            return root;
        }
        else if (leftans != NULL)
        {
            return leftans;
        }
        else
            return rightans;
    }
};
//**************
int main()
{

    return 0;
}