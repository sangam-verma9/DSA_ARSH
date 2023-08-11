#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *merge(Node *head1, Node *head2)
    {
        Node *finallist = new Node(0);
        Node *temp = new Node(0);
        finallist = temp;
        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }
        while (head1)
        {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        while (head2)
        {
            temp->next = head1;
            temp = head2;
            head2 = head2->next;
        }
        return finallist->next;
    }
    Node *findmid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *sort(Node *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        Node *mid = new Node(0);
        Node *head2 = new Node(0);
        mid = findmid(head);
        head2 = mid->next;
        mid->next = NULL;
        Node *final = merge(sort(head), sort(head2));
        return final;
    }
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // your code here
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        // Node* ans=sort(head);

        return NULL;
        // return ans;
    }
};
int main()
{

    return 0;
}