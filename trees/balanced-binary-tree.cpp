#include <bits/stdc++.h>
using namespace std;
// ********** good approach ********
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
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (abs(height(root->left) - height(root->right)) <= 1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else
            return false;
    }
};
//******** another good approach ********
class Solution
{
public:
    pair<bool, int> isBalancedfast(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<bool, int> left = isBalancedfast(root->left);
        pair<bool, int> right = isBalancedfast(root->right);

        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = abs(left.second - right.second) < 2 ? true : false;
        pair<bool, int> ans;
        ans.first = (op1 && op2 && op3);
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    bool isBalanced(TreeNode *root)
    {
        return isBalancedfast(root).first;
    }
};
//**********
int main()
{

    return 0;
}