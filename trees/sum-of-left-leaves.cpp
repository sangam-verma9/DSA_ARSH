#include <bits/stdc++.h>
using namespace std;
//***** optimized copyed from leetcode
class Solution
{
public:
    void solve(TreeNode *root, bool isLeft, int &sum)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (isLeft)
                sum += root->val;
        }
        solve(root->left, true, sum);
        solve(root->right, false, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        bool isLeft = false;
        int sum = 0;
        solve(root, isLeft, sum);
        return sum;
    }
};
//*********
int main()
{

    return 0;
}