#include <bits/stdc++.h>
using namespace std;
// ***** first approach ****** TC:O(N^2)
/*  1) Initialize current node as head.
    2) While next of current node is not null, do following
        a) Find the last node, remove it from the end and insert it as next
        of the current node.
        b) Move current to next of current
*/

//****** optimized approach *****  TC:O(N)
void reverselist(Node **head)
{
    // Initialize prev and current pointers
    Node *prev = NULL, *curr = *head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void rearrange(Node **head)
{
    // 1) Find the middle point using tortoise and hare
    // method
    Node *slow = *head, *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2) Split the linked list in two halves
    // head1, head of first half    1 -> 2
    // head2, head of second half   3 -> 4
    Node *head1 = *head;
    Node *head2 = slow->next;
    slow->next = NULL;
    // 3) Reverse the second half, i.e.,  4 -> 3
    reverselist(&head2);
    // 4) Merge alternate nodes
    *head = newNode(0); // Assign dummy Node
    // curr is the pointer to this dummy Node, which will
    // be used to form the new list
    Node *curr = *head;
    while (head1 || head2)
    {
        // First add the element from list
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        // Then add the element from the second list
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    // Assign the head of the new list to head pointer
    *head = (*head)->next;
}
//***********

int main()
{

    return 0;
}