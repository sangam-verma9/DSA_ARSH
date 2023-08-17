#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solvepre(Node *root, Node *&pre, int key)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->key >= key)
        {
            return solvepre(root->left, pre, key);
        }
        else if (root->key < key)
        {
            pre = root;
            return solvepre(root->right, pre, key);
        }
    }
    void solvesuc(Node *root, Node *&suc, int key)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->key > key)
        {
            suc = root;
            return solvesuc(root->left, suc, key);
        }
        else if (root->key <= key)
        {
            return solvesuc(root->right, suc, key);
        }
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        solvepre(root, pre, key);
        solvesuc(root, suc, key);
    }
};
int main()
{

    return 0;
}