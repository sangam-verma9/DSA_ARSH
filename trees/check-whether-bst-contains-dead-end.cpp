#include <bits/stdc++.h>
using namespace std;
//******* recursive solution ******* (copyed form gfg)******

/*First of all, it is given that it is a BST and nodes are greater than zero, root node can be in the range [1, ?] and if root val is say, val, then left sub-tree can have the value in the range [1, val-1] and right sub-tree the value in range [val+1, ?].
we need to traverse recursively and when the min and max value of range coincided it means that we cannot add any node further in the tree.
Hence we encounter a dead end. */

bool solve(Node *root, int min_val, int max_val)
{
    if (root == NULL)
    {
        return false;
    }
    if (min_val == max_val)
    {
        return true;
    }
    return solve(root->left, min_val, root->data - 1) || solve(root->right, root->data + 1, max_val);
}
bool isDeadEnd(Node *root)
{
    int min_val = 1;
    int max_val = INT_MAX;
    return solve(root, min_val, max_val);
}
//********** iterative solution *******
/*If we take a closer look at the problem, we can notice that we basically need to check if there is a leaf node with value x such that x+1 and x-1 exist in BST with the exception of x = 1. For x = 1, we can’t insert 0 as the problem statement says BST contains positive integers only.
To implement the above idea we first traverse the whole BST and store all nodes in a set. We also store all leaves in a separate hash to avoid re-traversal of BST. Finally, we check for every leaf node x, if x-1 and x+1 are present in set or not.*/
void storeNodes(Node *root, unordered_set<int> &all_nodes,
                unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return;

    // store all node of binary search tree
    all_nodes.insert(root->data);

    // store leaf node in leaf_hash
    if (root->left == NULL && root->right == NULL)
    {
        leaf_nodes.insert(root->data);
        return;
    }

    // recur call rest tree
    storeNodes(root->left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}

// Returns true if there is a dead end in tree,
// else false.
bool isDeadEnd(Node *root)
{
    // Base case
    if (root == NULL)
        return false;

    // create two empty hash sets that store all
    // BST elements and leaf nodes respectively.
    unordered_set<int> all_nodes, leaf_nodes;

    // insert 0 in 'all_nodes' for handle case
    // if bst contain value 1
    all_nodes.insert(0);

    // Call storeNodes function to store all BST Node
    storeNodes(root, all_nodes, leaf_nodes);

    // Traversal leaf node and check Tree contain
    // continuous sequence of
    // size tree or Not
    for (auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++)
    {
        int x = (*i);

        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if (all_nodes.find(x + 1) != all_nodes.end() &&
            all_nodes.find(x - 1) != all_nodes.end())
            return true;
    }

    return false;
}
//**********
int main()
{

    return 0;
}