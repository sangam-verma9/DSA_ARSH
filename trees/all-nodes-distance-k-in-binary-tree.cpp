#include <bits/stdc++.h>
using namespace std;
//****** good solution (copyed from leetcode) ******
class Solution
{
public:
    vector<int> ans;
    map<TreeNode *, TreeNode *> parent; // son=>parent
    set<TreeNode *> visit;              // record visied node

    void findParent(TreeNode *node)
    {
        if (!node)
            return;
        if (node->left)
        {
            parent[node->left] = node;
            findParent(node->left);
        }
        if (node->right)
        {
            parent[node->right] = node;
            findParent(node->right);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (!root)
            return {};

        findParent(root);
        dfs(target, K);
        return ans;
    }
    void dfs(TreeNode *node, int K)
    {
        if (visit.find(node) != visit.end())
            return;
        visit.insert(node);
        if (K == 0)
        {
            ans.push_back(node->val);
            return;
        }
        if (node->left)
        {
            dfs(node->left, K - 1);
        }
        if (node->right)
        {
            dfs(node->right, K - 1);
        }
        TreeNode *p = parent[node];
        if (p)
            dfs(p, K - 1);
    }
};
//***** second same as first but here we use vector instead of set ******
class Solution
{
public:
    void findparent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            parent[root->left] = root;
            findparent(root->left, parent);
        }
        if (root->right)
        {
            parent[root->right] = root;
            findparent(root->right, parent);
        }
    }
    void solve(TreeNode *node, vector<int> &ans, vector<TreeNode *> &visited, int k, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        if (find(visited.begin(), visited.end(), node) != visited.end())
        {
            return;
        }
        visited.push_back(node);
        if (k == 0)
        {
            ans.push_back(node->val);
            return;
        }
        if (node->left)
        {
            solve(node->left, ans, visited, k - 1, parent);
        }
        if (node->right)
        {
            solve(node->right, ans, visited, k - 1, parent);
        }
        TreeNode *p = parent[node];
        if (p)
        {
            solve(p, ans, visited, k - 1, parent);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root)
        {
            return {};
        }
        unordered_map<TreeNode *, TreeNode *> parent;
        findparent(root, parent);
        vector<int> ans;
        vector<TreeNode *> visited;
        solve(target, ans, visited, k, parent);
        return ans;
    }
};
//**********
int main()
{

    return 0;
}