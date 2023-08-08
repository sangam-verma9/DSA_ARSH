#include <bits/stdc++.h>
using namespace std;
//********* first think **********
class Solution
{
public:
    void solve(Node *head, Node *&head1)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = new Node(head->val);
        head1->next = temp;
        temp->prev = head1;
        head1 = temp;
        solve(head->child, head1);
        solve(head->next, head1);
    }
    Node *flatten(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *head1 = new Node(0); // assign a new node val 0
        Node *ans = head1;
        solve(head, head1);
        ans->next->prev = NULL; // for removing fist node that is assign 0 by user
        return ans->next;
    }
};
//*********
int main()
{

    return 0;
}