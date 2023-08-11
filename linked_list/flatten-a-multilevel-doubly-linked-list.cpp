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
//********* optimized approach (copy from leetcode)
class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *ptr = head, *tmp_next, *runner;

        while (ptr)
        {
            if (ptr->child)
            {

                // Save the current next and connect the child to next
                tmp_next = ptr->next;
                ptr->next = ptr->child;
                ptr->next->prev = ptr;
                ptr->child = NULL;

                // Run till the end of the current list and connect last node to saved next
                runner = ptr->next;
                while (runner->next)
                    runner = runner->next;
                runner->next = tmp_next;
                if (runner->next)
                    runner->next->prev = runner;
            }

            ptr = ptr->next;
        }

        return head;
    }
};
//*********
int main()
{

    return 0;
}