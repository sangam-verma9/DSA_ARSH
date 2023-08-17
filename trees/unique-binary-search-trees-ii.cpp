#include <bits/stdc++.h>
using namespace std;
//******** recursive approach (copyed from leetcode) *******
class Solution
{
public:
    vector<TreeNode *> solve(int s, int e)
    {
        vector<TreeNode *> ans;
        if (s > e)
        {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = s; i <= e; i++)
        {
            vector<TreeNode *> leftsubtree = solve(s, i - 1);
            vector<TreeNode *> rightsubtree = solve(i + 1, e);
            for (int j = 0; j < leftsubtree.size(); j++)
            {
                for (int k = 0; k < rightsubtree.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftsubtree[j];
                    root->right = rightsubtree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};
//**********
int main()
{

    return 0;
}