#include <bits/stdc++.h>
using namespace std;
//**** brute force *****
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return root;
        }
        TreeNode *temp = invertTree(root->left);
        TreeNode *temp2 = invertTree(root->right);
        root->left = temp2;
        root->right = temp;
        return root;
    }
};
//**** good but not optimized*****
class Solution
{
public:
    void invert(TreeNode *&t1, TreeNode *&t2)
    {
        if (t1 == NULL && t2 == NULL)
        {
            return;
        }
        else if (t1 == NULL && t2 != NULL)
        {
            t1 = t2;
            t2 = NULL;
            return invert(t1->left, t1->right);
        }
        else if (t1 != NULL && t2 == NULL)
        {
            t2 = t1;
            t1 = NULL;
            return invert(t2->left, t2->right);
        }
        TreeNode *temp = t2;
        t2 = t1;
        t1 = temp;
        invert(t1->left, t1->right);
        invert(t2->left, t2->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        invert(root->left, root->right);
        return root;
    }
};
//******** optimized approach ********
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
            return NULL;
        invertTree(root->left);  // Call the left substree
        invertTree(root->right); // Call the right substree
        // Swap the nodes
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root; // Return the root
    }
};
//**********
int main()
{

    return 0;
}