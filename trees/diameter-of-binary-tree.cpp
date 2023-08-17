#include <bits/stdc++.h>
using namespace std;
//******** first approach ******
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    int findDia(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int curr = height(root->left) + height(root->right);
        int left = findDia(root->left);
        int right = findDia(root->right);
        return max(curr, max(left, right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        return findDia(root);
    }
};
//********** optimized approach *******
class Solution
{
public:
    int height(TreeNode *root, int &d)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lefth = height(root->left, d);
        int righth = height(root->right, d);
        d = max(d, lefth + righth);
        return 1 + max(lefth, righth);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        height(root, d);
        return d;
    }
};
//**********
int main()
{

    return 0;
}