#include <bits/stdc++.h>
using namespace std;
// ******* good but not space optimized in leetcode *****
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
};
// ********* optimized ******
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
//********
int main()
{

    return 0;
}