#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        // cout<<root->val;
        inorder(root->right, v);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};
int main()
{

    return 0;
}