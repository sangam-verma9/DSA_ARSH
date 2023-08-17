#include <bits/stdc++.h>
using namespace std;
//*********** first approcah **********
class Solution
{
public:
    void solve(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int m = INT_MAX;
        vector<int> v;
        solve(root, v);
        for (int i = 0; i < v.size() - 1; i++)
        {
            int a = v[i + 1] - v[i];
            m = min(m, a);
        }
        return m;
    }
};
//********** good approach **********
class Solution
{
public:
    void solve(TreeNode *root, int &prev, int &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, prev, ans);
        if (prev != -1)
        {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;
        solve(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int prev = -1;
        int ans = INT_MAX;
        solve(root, prev, ans);
        return ans;
    }
};
//**********
int main()
{

    return 0;
}