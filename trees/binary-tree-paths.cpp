#include <bits/stdc++.h>
using namespace std;
//******* first approach (100% beats in TC)
class Solution
{
public:
    void solve(TreeNode *root, vector<string> &ans, string s)
    {
        if (root->left == NULL && root->right == NULL)
        {
            s += to_string(root->val);
            ans.push_back(s);
            s.clear();
            return;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            s += to_string(root->val);
            s += "->";
            solve(root->left, ans, s);
        }
        else if (root->left == NULL && root->right != NULL)
        {
            s += to_string(root->val);
            s += "->";
            solve(root->right, ans, s);
        }
        else
        {
            s += to_string(root->val);
            s += "->";
            solve(root->left, ans, s);
            solve(root->right, ans, s);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string s = "";
        solve(root, ans, s);
        return ans;
    }
};
//**********
int main()
{

    return 0;
}